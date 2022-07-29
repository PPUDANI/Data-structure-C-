#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> stk;
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