#include <iostream>
using namespace std;

long long fibonacci(int n){
    if(n <= 1){
        return n;
    }
    return fibonacci(n - 2) + fibonacci(n - 1);
}

int main(){
    for(int i = 1; i <=10; i++)
        cout << fibonacci(i) << endl;
}