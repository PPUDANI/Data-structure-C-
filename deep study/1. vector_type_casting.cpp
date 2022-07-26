#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<char> a = {'1','2','a','A','t'};
    // vector 형변환 출력
    for(const int &i : a){
        cout << i << endl;
    }

    return 0;
}