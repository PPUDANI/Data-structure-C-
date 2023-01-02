#include <iostream>
using namespace std;
template<typename T>
class DynamicArray{
private:
    unsigned int sz;
    T* arr;

public:

    explicit DynamicArray (int n) : sz(n){
        arr = new T[sz] {};
    };

    ~DynamicArray(){
        delete [] arr;
        arr = nullptr;
        cout << "memory deleted! "<< endl;
        cout << arr;
    };

    const unsigned int size () const{
       return sz;
    }

    T& operator[] (const int i) {
        return arr[i];
    }

};

int main(){

    DynamicArray <int> arr(3);
    for(int i = 0; i < arr.size(); i++){
        arr[i] = i;
    }

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << endl;
    }

}