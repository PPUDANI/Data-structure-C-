#include <iostream>
#include <chrono>

using namespace std;

int main(){

        auto start = chrono::system_clock::now();
        volatile int s = 0;

        for(int n = 0; n < 5000; n++){
            for(int i = 0; i < n; i++){
                s += i;
            }
        }
            

        auto end = chrono::system_clock::now();
        auto mesc = chrono::duration<double>(end - start).count() * 1000;
        cout << "sum_recursive(): " << mesc << "ms" << endl;

}
    