#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Linked_list{
private:
    Node* head;
public:
    Linked_list(): head(NULL){}
    ~Linked_list(){
        while(!empty()){
            pop_front();
        }
    }

    void push_front(int val){
        // 동적할당을 하는 이유는 이 멤버함수가 끝나도 해당 데이터가 소멸하지 않기 때문이다.
        Node* new_node = new Node{val, NULL};
        new_node -> next = head;
        head = new_node;
    }

    void pop_front(){
        Node* temp = head;
        head = head -> next;
        delete temp;
    }

    void print_all(){
        Node* curr = head;
        while(curr != NULL){
            cout << curr -> data << " ";
            curr = curr -> next;
        }
    }

    bool empty(){
        return (head == NULL)? true : false;
    }
};
int main(){
    Linked_list a;
    a.push_front(10);
    a.push_front(20);
    a.push_front(30);
    a.print_all();
}