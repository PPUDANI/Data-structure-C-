#include <iostream>
using namespace std;
template <typename T>
struct Node{
    Node* next;
    T data;
};

template <typename T>
class LinkedList{
private:
    Node<T>* head;
    
public:
    LinkedList () : head(NULL) {};
    ~LinkedList () {
        while(!empty()){
            pop_front();
        }
    };

    void push_front (T data) {
        Node<T> new_node = new Node<T>{data, NULL};
        new_node -> next = head;
        head = new_node;
    }

    void pop_front () {
        Node* temp = head;
        head = new_node -> next;
        delete temp;
    }

    void print_All () {
        Node* curr = head;
        while(curr != NULL){
            cout << curr -> data << " ";
            curr = curr -> next;
        }
    }

    bool empty () {
        return (head == NULL) ? true : false;
    }
};

int main(){

    LinkedList<int> i_LL;

    i_LL.push_front(10);
    i_LL.push_front(2);
    i_LL.push_front(45);
    i_LL.print_All();
    i_LL.pop_front();
    i_LL.pop_front();
    i_LL.print_All();
}


