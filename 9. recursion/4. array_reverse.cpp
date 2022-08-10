#include <iostream>
using namespace std;

// str.substr(n)은 문자열의 n번 째에 해당하는 문자부터 문자열 끝사이의
// 문자열 부분을 추출해서 새로운 문자열을 만든다.
        
string reverse(const string& str){
    if(str.length() == 0)
        return "";
    else
        return reverse(str.substr(1)) + str[0];  
}
int main(){
    cout << reverse("Hello") << endl;
}