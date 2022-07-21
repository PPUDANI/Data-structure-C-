#include <iostream>
using namespace std;

int main()
{
    int scores[5] = {50, 60, 70, 80, 90};
    // int sz = sizeof(scores) / sizeof(int);
    int sz = size(scores); 
    int sum = 0;

    for(int i = 0; i < sz; i++){
        sum += scores[i];
    }

    float m = (float)sum / sz;
    cout << "mean score: " << m << endl;
}