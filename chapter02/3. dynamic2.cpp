#include<iostream>
using namespace std;
template <typename T>

class DynamicArray
{
private:
    unsigned int sz;
    T* arr;

public:
    //explicit란 명백한이라는 뜻으로 자신이 원하지 않은
    //형변환이 일어나지 않도록 제한하는 키워드이다.
    //생성자함수에 형변환 방지를 위해 적은 것으로 생략가능
    explicit DynamicArray (int n) : sz(n){
        arr = new T[sz] {};
    }

    ~DynamicArray(){
        delete [] arr;
        cout << "memory deleted" << endl;
    }

    unsigned int size() {return sz;}

    T& operator[] (const int i){ return arr[i];  }

    const T& operator[](const int i) const { return arr[i]; }
};

int main()
{
    DynamicArray <float> da(5);

    // 위 선언부에 template<typename T> 를 선언하고
    // 변수 자료형을T로 설정하고 주석 위 처럼 <자료형>을
    // 적어주면 해당 자료형으로 바꾸어 연산이 가능하다.
    //
    // (예시코드)
    // T sum(T a, T b){ return a+b;}
    //
    // int a1, b1;
    // string a2, b2;
    // double a3, b3;
    //
    // cout << sum <int>(a1,b1) << endl;
    // cout << sum <string>(a2,b2)<< endl;
    // cout << sum <double>(a3,b3)<< endl;

    const float a = 1;
    da[0] = 10.3f;
    da[a] = 20.4f;
    da[2] = 30.0f;
    for(int i = 0; i < da.size(); i++){
        cout << da[i] << endl;
    }
}