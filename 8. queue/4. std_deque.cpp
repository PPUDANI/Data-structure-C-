#include <iostream>
#include <deque>
using namespace std;
// std::deque는 std::stack와 std::queue에 주로 사용되는 컨테이너이다.
// 메모리를 chunk 단위로 관리하며 메모리가 넘치면 새로운 청크를 만들어서
// 해당 청크에 데이터를 저장한다.
int main(){
    deque<int> d {10, 20, 30, 40};

    d.push_front(50);
    d.push_back(60);

    for(auto i : d){
        cout << i << ", ";
    }
    cout << endl;
}