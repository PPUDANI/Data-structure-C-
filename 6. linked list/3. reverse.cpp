#include <iostream>
#include <stack>
#include <vector>
using namespace std;

string reverse(const string& str)
{
    stack<char> stk;

    for(char c : str)
        stk.push(c);

    string res;
    
    while (!stk.empty()){
        res += stk.top();
        stk.pop();
    }
    return res;
}

template <typename T>
void reverse(vector<T>& vec){
    stack<T, vector<T>> stk(vec);
    stack<T> stk;
    for(auto e : vec)
        stk.push(e);

    for(int i = 0; i < vec.size();i++){
        vec[i] = stk.top();
        stk.pop();
    } 
}

int main()
{
    string str1 = "HELLO";
    string str2 = "ALGORITHM";
    string str3 = "RACECAR";
    cout << reverse(str1) << endl;
    cout << reverse(str2) << endl;
    cout << reverse(str3) << endl;

    vector<int> vec1 {10, 20, 30, 40, 50};
    vector<string> vec2 {"john", "loves", "Jane"};
    reverse<int>(vec1);
    reverse<string>(vec2);
    for(auto e: vec1)
        cout << e << ", ";
    cout << endl;

    for(auto e: vec2)
        cout << e << " ";
    cout << endl;
}