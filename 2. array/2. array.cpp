# include <iostream>
#include <array>
using namespace std;

int main(){
    // c++ 스타일의 정적 배열 array라는 클래스이며 operator[]로 c의 배열과 같이 사용할 수 있다.
    // 멤버함수 size()로 배열의 크기를 리턴할 수 있다.(arr[5]로 정의되었으면 arr.size()는 5가 된다.)
    // (c는 sizeof()로 파라메터값을 받고 자료형으로 직접 나누어서 사용했음.)

    // c언어의 정적 배열 스타일을 그대로 사용할 수 있다. 하지만 단점이 있다.
    // 1. 배열의 크기를 명시적으로 작성해야한다.
    // 2. c와 같이 정적배열은 스택 메모리를 사용하므로 1~2MB 이상 메모리를 차지하면 스택오버플로우가 발생함.
    // 3. 정적 배열보다 가변크기를 더 자주 사용하여 array는 잘 사용안하고 동적 배열인 vector를 사용한다.

    array<int ,5> arr = {10, 2, 30, 45, 32};
    int sum = 0;

    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
    }

    float mean = sum / arr.size();

    cout << "평균은 " << mean << " 입니다."<<endl;

    // array로 이차배열 생성
    array<array<int, 2>,3> arr1 = {1, 2, 3, 4, 5, 6};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            cout << arr1[i][j] << " " << endl;
        }
    }

}