#include <iostream>
#include <queue>
using namespace std;
//std::queue이다. c++에서 기본으로 제공하는 queue로 컨테이너는
int main(){
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << q.size() << endl;

    while(!q.empty()){
        cout << q.front() << ", ";
        q.pop();
    }
}