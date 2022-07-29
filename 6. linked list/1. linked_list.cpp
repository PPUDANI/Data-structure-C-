#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList(): head(NULL){}
    ~LinkedList(){
        while(!empty()){
            pop_front();
        }
    }

    void push_front(int val){
        Node* new_node = new Node {val, NULL};
        if(head != NULL){
            new_node -> next = head;
        }
        head = new_node;
    }

    void pop_front(){
        if(head == NULL){
            return;
        }
        Node* first = head;
        head = head -> next;
        delete first;
    }

    int& front(){
        return head->data;
    }

    void print_all(){
        Node* curr = head;
        
        while(curr != NULL){
            cout << curr -> data <<", ";
            curr = curr -> next;
        }
        cout << endl;
    }

    bool empty(){
        return head == NULL;
    }
    
};
int main()
{
    LinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.print_all();

    ll.pop_front();
    ll.push_front(40);
    ll.print_all();

}