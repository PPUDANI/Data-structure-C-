#include <iostream>
using namespace std;

int main(){
    double a, b;
    cin >> a;
    cin >> b;
    
    double res = a / b;
    cout.precision(9);
    cout << res;
    return 0;
}
