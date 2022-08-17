#include <iostream>
#include <vector>
using namespace std;

void print_vec(vector<int>& data){
    for(int i: data){
        cout << i << ", ";
    }  
    cout << endl;
}

void bubble_sort(vector<int>& data){
    int n = data.size();
    print_vec(data);
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = n - 1; j >= 1; j--){
            if(data[j] < data[j-1])
                swap(data[j-1], data[j]);
            else
                count++; 
        }
        print_vec(data);
        if(count == n - 1){
            return;
        }
    }
}

int main(){
    vector<int> vec1 = {2,5,3,1,4};
    vector<int> vec2 = {2,4,5,3,1};
    vector<int> vec3 = {5,4,1,3,2};

    cout << "\n<vec1 sort>" << endl; 
    bubble_sort(vec1);
    cout << "\n<vec2 sort>" << endl; 
    bubble_sort(vec2);
    cout << "\n<vec3 sort>" << endl; 
    bubble_sort(vec3);
}