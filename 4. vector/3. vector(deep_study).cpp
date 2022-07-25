#include <iostream>
#include <vector>
using namespace std;

void VectorOut(vector <int> vec)
{
    // 이렇게 함수에서 벡터를 인자로 받을 때 받은 vector에 저장된 데이터만 가져와서 
    // capccity가 가저온 데이터의 사이즈로 바뀜
    cout << "capacity/size : " << vec.capacity() << "/" << vec.size() << " data : ";
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector <int> v1(3);
    vector <int> v2(3, 1);
    vector <int> v3{1, 2, 3};
    vector <int> v4(v3);
    VectorOut(v1);
    VectorOut(v2);
    VectorOut(v3);
    VectorOut(v4);

    cout << "이전 v4의 용량: "<< v4.capacity() << endl;
    v4.push_back(4); // 배열 뒤에 값 추가. 만약 벡터에 데이터가 차있으면 기존 벡터의 데이터를 복사해서
                     // 2배의 크기의 새로운 벡터를 생성해서 복사한 데이터를 저장하고 기존 벡터는 삭제함.
                     // 참고로 size()는 vector의 데이터의 개수를 반환하고, capacity는 vector의 총 용량을 반환함.
    cout << "push_back 연산 후 v4의 용량: "<< v4.capacity() << endl;
    v4.push_back(5); //
    VectorOut(v4);

    
    v4.erase(v4.begin()+1,v4.begin()+2 ); // 주소+1 데이터부터 주소+2 전까지의 데이터 삭제 (O(n)이라 효율 떨어짐)
    VectorOut(v4);
    v4.insert(v4.begin()+3, 9); //해당 주소에 값을 넣고 뒤에 데이터는 다밀림 (O(n)이라 효율 떨어짐)
    VectorOut(v4);

    v4.pop_back();
    for(int i = 0; i < v4.capacity(); i++){
        cout << v4[i] << " ";
    }

}