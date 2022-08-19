#include <iostream>
#include <vector>
using namespace std;

void print_vec(vector<int>& data){
    for(int i: data){
        cout << i << ", ";
    }  
    cout << endl;
}

void selection_sort(vector<int>& data){
    int n = data.size();
    
    for(int i = 0; i < n; i++){
        int idx = i;
        for(int j = i+1; j < n; j++){
            if(data[j] < data[idx]){
                idx = j;
            }
        }
        swap(data[i],data[idx]);
        print_vec(data);
    }
}

int main(){
    vector<int> vec1 = {2,5,3,1,4};
    vector<int> vec2 = {2,4,5,3,1};
    vector<int> vec3 = {5,4,1,3,2};

    cout << "\n<vec1 sort>" << endl; 
    selection_sort(vec1);
    cout << "\n<vec2 sort>" << endl; 
    selection_sort(vec2);
    cout << "\n<vec3 sort>" << endl; 
    selection_sort(vec3);
}