#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

class D_linked_list{
private:
    int count = 0;
    Node* header;
    Node* trailer;
public:
    D_linked_list(){
        header = new Node{0, NULL, NULL};
        trailer = new Node{0, NULL, NULL};
    }
    ~D_linked_list(){
        while(count != 0){
            
            cout << "count = " << count << endl;
            pop_front();
        }
        cout << "동적메모리 해제 완료" << endl;
    }

    void push_front(int val){
        Node* new_Node = new Node{val, NULL, NULL};

        //뒤 연결
        if(count == 0){
            new_Node -> next = trailer;
            trailer -> prev = new_Node;
        }
        else{
            header -> next -> prev = new_Node;
            new_Node -> next = header -> next;
        }
        
        //앞 연결
        header -> next = new_Node;
        new_Node -> prev = header;
        
        count++;
    }

    void pop_front(){
        Node* first = header -> next;
        if(count == 0){
            cout << "더 이상 데이터가 존재하지 않습니다." << endl;
            return;
        }
        header -> next -> next -> prev = header;
        header -> next = header -> next -> next;
        count--;
        delete first;
    }

    void print_Leftfirst(){
        Node* curr = header -> next;
        int cnt = count;
        while(cnt != 0){
            cout << curr -> data << " ";
            curr = curr -> next;
            cnt--;
        }
        cout << endl;
    }

    void print_Rightfirst(){
        Node* curr = trailer -> prev;
        int cnt = count;
        while(cnt != 0){
            cout << curr -> data << " ";
            curr = curr -> prev;
            cnt--;
        }
        cout << endl;
    }
    void print_count(){
        cout << "데이터의 개수는 " << count << "개 입니다." << endl;
    }
};
int main(){
    D_linked_list DLL;

    DLL.push_front(1);

    DLL.print_count();
    DLL.print_Leftfirst();
    DLL.print_Rightfirst();
    cout << endl;

    DLL.push_front(2);
    DLL.push_front(3);

    DLL.print_count();
    DLL.print_Leftfirst();
    DLL.print_Rightfirst();
    cout << endl;
    
    DLL.push_front(4); 
    DLL.push_front(5);

    DLL.print_count();
    DLL.print_Leftfirst();
    DLL.print_Rightfirst();
    cout << endl;

    DLL.pop_front();
    DLL.print_count();
    DLL.print_Leftfirst();
    DLL.print_Rightfirst();
    cout << endl;
}