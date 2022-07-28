#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v1;
    vector<int> v2(10);
    vector<double> v3(10, 1.2f);


    for(int i : v2){
        cout << i << " ";
    }

    cout << endl;

    for(double i : v3){
        cout << i << " ";
    }
    

}