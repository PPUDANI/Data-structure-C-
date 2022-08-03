#include <iostream>
#include <list>
using namespace std;

template <typename T>
class Queue{
private:
    list<T> lst;
public:
    Queue(){};
    void enqueue(const T& e){ lst.push_back(e);}  
    void dequeue(){lst.pop_front();}
    const T& front() const {return lst.front();}
    bool empty() const {return lst.empty();}
    int size()const {return lst.size();}

};
int main(){
    Queue<int> que1;

    que1.enqueue(30);
    que1.enqueue(20);
    que1.enqueue(10);
    que1.enqueue(40);
    cout << que1.size() << endl;

    while(!que1.empty()){
        cout << que1.front() << ", ";
        que1.dequeue();
    }
}