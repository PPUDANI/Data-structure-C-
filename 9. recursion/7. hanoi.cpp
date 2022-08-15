#include <iostream>
using namespace std;

void hanoi(int n, int from = 1, int to = 3, int by = 2){
    if(n == 1){
        cout << from << " -> " << to << endl;
    }
    else{
       hanoi(n - 1, from, by, to);
       cout << from << " -> " << to << endl; 
       hanoi(n - 1, by, to, from);
    }   
}
int main(){
    hanoi(5);
}