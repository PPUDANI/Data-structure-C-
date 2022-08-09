#include <iostream>
#include <utility>
using namespace std;

using pis = pair<int, string>;
void same(pair<int, string> a, pair<int, string> b){
    if(a == b){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}
int main()
{
    pis p1= make_pair(1, "skr");
    pis p2= make_pair(1, "skr");
    pis p3= make_pair(2, "skr");

    cout << p1.first << ". " << p1.second << endl;
    cout << p2.first << ". " << p2.second << endl;
    cout << p3.first << ". " << p3.second << endl;

    cout << "p1 == p2? ";
    same(p1,p2);

}