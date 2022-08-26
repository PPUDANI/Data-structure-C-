#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void print_data(vector<int>& data){
    for(int i : data){
        cout << i << ", ";
    }
    cout << endl;
}
int patition(vector<int>& data, int left, int right){
    int pivot = data[left];
    int i = left + 1, j = right;
    
    while(true){
        while(data[i] <= pivot && i < right)
            i++;
        while(data[j] > pivot && j > left)
            j--;
        if(i < j){
            swap(data[i], data[j]);
            cout << "1" << endl; 
            print_data(data);
        }
        else{
            break;
        }   
    }
    swap(data[left], data[j]);
    
    print_data(data);
    cout << "left = " << left+1 << " j = " << j+1 << " right = " << right+1 << "\n" << endl;
    return j;

}
void quick_sort(vector<int>& data, int left, int right){
    if(left < right){
        int p = patition(data, left, right);
        quick_sort(data, left, p - 1);
        quick_sort(data, p+1, right);
    }
    else{
        print_data(data);
        cout << "left = " << left+1 << " right = " << right+1 << " (실행X)\n"<< endl;
    }
}

int main(){
    vector <int> v1 {4, 6, 3, 8, 5, 2, 7, 1};
    quick_sort(v1, 0, 7);
    for(int i : v1){
        cout << i << ", ";
    }
}