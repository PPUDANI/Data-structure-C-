#include<iostream>
using namespace std;
#define MAX_QUEUE 10
// 환형 큐이다. 만들어진 이유는 rightword drift 로 인해 계속 메모리가 이동하는것과
// 사용하다보면 쓰이지않는 데이터들로 인해 저장공간이 낭비가 되기 때문에 환형 큐가
// 만들어졌다.
template <typename T>
class CirclularQueue{
private:
    T* arr;
    int front_idx;
    int rear_idx;
    int count;
    int capacity;
public:
    CirclularQueue(int sz = MAX_QUEUE){
        arr = new T[sz];
        front_idx = 0;
        rear_idx = -1;
        count = 0;
        capacity = sz;
    }
    ~CirclularQueue(){
        delete [] arr;
    }

    void enqueue(const T& e){
        if(full()){
            cout << "Overflow error!" << endl;
            return;
        }
        rear_idx = (rear_idx + 1) % capacity;
        arr[rear_idx] = e;
        count++;
    }

    void dequeue(){
        if(empty()){
            cout << "Underflow error!" << endl;
            return;
        }
        front_idx = (front_idx+1) % capacity;
        count --;
    }

    const T& front() const { return arr[front_idx]; }

    bool full() const { return count == capacity; }
    bool empty() const { return count == 0; }
    int size() const { return count;}

};

int main(){
    CirclularQueue<int> cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.dequeue();
    cq.dequeue();

    cq.enqueue(32);
    cq.enqueue(18);

    while(!cq.empty()){
        cout << cq.front() << ", ";
        cq.dequeue();
    }
}