#include <iostream>
#include <numeric>
using namespace std;

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main(){
    cout << "<function>"<<endl;
    cout << "gcd: " << gcd(10, 15) << endl;
    cout << "lcm: " << lcm(10, 15) << endl;
    cout << "\n<numeric>"<<endl;
    cout << "std::gcd: " << std::gcd(10, 15) << endl;
    cout << "std::lcm: " << std::lcm(10, 15) << endl;
}