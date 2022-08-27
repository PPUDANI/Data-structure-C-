#include<iostream>
#include<vector>
using namespace std;

using vpis = vector<pair<int, string>>;
int main(){

    vpis vp1;
    vp1.push_back(pair<int, string>(1.1f,"apple"));
    vp1.push_back({2.0f,"banana"}); //이렇게 써도 됨

    for(pair<int, string> i : vp1){
        cout << i.second << endl;
    }

    for(pair<double, string> i : vp1){
        cout << i.first << " "<<  i.second << endl;
    }
}