#include <iostream>
using namespace std;

int main()
{
    int scores[5] = {50, 60, 70, 80, 90};
    // C언어는 이렇게 사용했음. 
    // int sz = sizeof(scores) / sizeof(int);
    // C++ 2017부터 아래처럼 사용할 수 있음.
    int sz = size(scores); 
    int sum = 0;

    for(int i = 0; i < sz; i++){
        sum += scores[i];
    }

    float m = (float)sum / sz;
    cout << "mean score: " << m << endl;
}