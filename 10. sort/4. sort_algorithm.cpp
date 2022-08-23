#include <iostream>
#include <vector>
using namespace std;

void print_vec(vector<int>& data){
    for(int i: data){
        cout << i << ", ";
    }  
    cout << endl;
}

void bubble_sort(vector<int> data){
    int n = data.size();
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = n-1; j >= 1; j--){
            if(data[j] < data[j-1]){
                swap(data[j-1], data[j]);
            }
            else{
                count++;
            }
        }
        if(count == data.size() - 1){
            return;
        }
        print_vec(data);
    }
}

void selection_sort(vector<int> data){
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

void insertion_sort(vector<int> data){
    int n = data.size();
    for(int i = 1; i < n; i++){
        int key = data[i];
        int j = i - 1;
        while(j >= 0 && data[j] > key){
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = key;
        print_vec(data);
    }
}


int main(){
    vector<int> vec1 = {2,5,3,1,4};
    vector<int> vec2 = {2,4,5,3,1};
    vector<int> vec3 = {5,4,1,3,2};

    cout << "--------------------" << endl;
    cout << "\n<vec1>: "; 
    print_vec(vec1);
    cout << "\n<Bubble sort>" << endl;
    bubble_sort(vec1);
    cout << "\n<selection sort>" << endl;
    selection_sort(vec1);
    cout << "\n<insertion sort>" << endl;
    insertion_sort(vec1);

    cout << "--------------------" << endl;
    cout << "\n<vec2>: "; 
    print_vec(vec2);
    cout << "\n<Bubble sort>" << endl;
    bubble_sort(vec2);
    cout << "\n<selection sort>" << endl;
    selection_sort(vec2);
    cout << "\n<insertion sort>" << endl;
    insertion_sort(vec2);

    cout << "--------------------" << endl;
    cout << "\n<vec3>: "; 
    print_vec(vec3);
    cout << "\n<Bubble sort>" << endl;
    bubble_sort(vec3);
    cout << "\n<selection sort>" << endl;
    selection_sort(vec3);
    cout << "\n<insertion sort>" << endl;
    insertion_sort(vec3);
}