#include<iostream>
#include<vector>
using namespace std;

void vecinfo(vector<int> vec){
    int count = 0;
    cout << "size: "<<vec.size() << "/ capacity: " <<vec.capacity() << endl;
    // size는 vector에 저장되어있는 데이터의 개수를 뜻하고, capacity는 총 용량을 뜻한다.
    for(int i = 0; i < vec.capacity(); i++){
        cout << vec[i];
        count++;
        if(i < vec.capacity()-1){
           cout << ", ";
        }
    }
    cout << endl << endl;
}
int main(){

    vector<int>v1;
    vector<int>v2(3);
    vector<int>v3(11,1);
    
    // v2로 실험을 해보면 capacity가 2의배수로 증가하는걸 볼 수 있다. 
    // 과정은 기존 vector의 두 배의 크기로 메모리를 할당받아 값을 복사하고 기존 vector를 지운다.
    // 함수의 파라메터 값으로 받을 시 capacity가 size와 같은 값인 것을 볼 수 있다.
    cout << "size: "<<v2.size() << "/ capacity: " <<v2.capacity() << endl;
    v2.push_back(3);
    v2.push_back(4);
    cout << "size: "<<v2.size() << "/ capacity: " <<v2.capacity() << endl;
    v2.push_back(5);
    v2.push_back(6);
    cout << "size: "<<v2.size() << "/ capacity: " <<v2.capacity() << endl;
    vecinfo(v2);

    vector<int>v4{10, 20, 30, 40};     // 10 20 30 40
    v4.insert(v4.begin()+3, 99);       // 10 20 30 99 40
    v4.erase(v4.begin(),v4.begin()+2); // 30 99 40
    cout << "size: "<<v4.size() << "/ capacity: " <<v4.capacity() << endl;
    vecinfo(v4);
    //위 결과를 보면 erase를 했음에도 capacity는 그대로 8인 것을 볼 수 있다.
    
    //게다가 데이터도 지워지지 않은 것을 알 수 있다.
    for(int i= 0; i < 6; i++){
        cout << v4[i] << " "; 
    }

}