#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1;// (빈 공간의 배열 생성)
    vector<int> v2(10);//(10개의 배열)
    vector<int> v3(10, 1); //(10개의 배열, 1의 값을 넣음)
    vector<int> v4{10, 20, 30, 40, 50}; //{}중괄호로 값넣기

    vector<int> v5(v4); // v4의 배열로 채움
    vector<int> v6(v4.begin(), v4.begin()+3); // v4의 시작주소부터  주소+3 까지의 값을 넣음

    for(int i = 0; i < v5.size();i++){
        cout << v5[i] << endl;
    }
    //2차원배열
    vector<vector<int>> mat1(2, vector<int>(3));

    vector<vector<int>> mat2 
    {
        {1, 2, 3},
        {4, 5, 6}
    };
    for(int r = 0; r < mat2.size(); r++){
        for(int c= 0; c < mat2[r].size(); c++){
            cout << mat2[r][c] << ", ";
        }
        cout << endl;
    }
}