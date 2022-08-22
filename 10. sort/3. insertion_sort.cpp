#include <iostream>
#include <vector>
using namespace std;

void print_vec(vector<int>& data){
    for(int i: data){
        cout << i << ", ";
    }  
    cout << endl;
}

void insertion_sort(vector<int>& data){
    int n = data.size();
    for(int i = 1; i < n; i++){
        int key = data[i];
        cout << "key 값: " << key << endl;
        for(int j = i-1; j >= 0; j--){
            if(key < data[j]){
                cout << key <<"이(가) " << data[j] <<" 보다 작다." << endl;
                data[j+1] = data[j];
                if(j == 0){
                    data[j] = key;
                    cout << "j이(가) " << j << "이므로 삽입" << endl;
                }
                print_vec(data);
            }
            else{
                data[j+1] = key;
                cout << key <<"이(가) " << data[j] <<" 보다 크므로 삽입." << endl;
                print_vec(data);
                break;
            }
        }
    }
}

int main(){
    vector<int> vec1 = {2,5,3,1,4};
    vector<int> vec2 = {2,4,5,3,1};
    vector<int> vec3 = {5,4,1,3,2};

    cout << "\n<vec1 sort>" << endl; 
    insertion_sort(vec1);
    cout << "\n<vec2 sort>" << endl; 
    insertion_sort(vec2);
    cout << "\n<vec3 sort>" << endl; 
    insertion_sort(vec3);
}