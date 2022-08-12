#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void print_vector(const vector<T>& vec){
    for(const auto &e : vec)
        cout << e << " ";
    cout << endl;
}

template<typename T>
void permutation(vector<T>& vec, int k)
{
    if (k == vec.size() - 1){
        print_vector(vec);
        return;
    }
    
    for (int i = k; i < vec.size(); i++){
        swap(vec[k], vec[i]);
        permutation(vec, k + 1);
        swap(vec[k], vec[i]);
    }
}

int main(){
    vector<int> vec {1, 2, 3, 4};
	permutation(vec, 0);

}