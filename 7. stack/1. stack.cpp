#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack{
private:
    vector<T> v;
public:
    Stack(){}
    void push(const T& e) { v.push_back(e); }
    void pop(){v.pop_back();}
    const T& top() const { return v.back(); }

    bool empty() const { return v.empty(); }
    int size() const  { return v.size(); }
};
int main(){
    Stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.pop();

    cout << stk.top() << endl;
    stk.push(40);

    while(!stk.empty()){
        cout << stk.top() << ", ";
        stk.pop();
    }
    cout << endl;
}