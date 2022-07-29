#include <iostream>
#include <list>
using namespace std;



int main()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_front(39);
    for(int n : l1){
        cout << n << ", ";
    }
    cout << endl;
    list<int>l2 {10, 20, 30, 40};

    for(int n : l2)
        cout << n << ", ";
    cout << endl;

    l2.splice(l2.end(), l1);

    for(int n : l1)
        cout << n << ", ";
    cout << endl;

    for(int n : l2)
        cout << n << ", ";
    cout << endl;

    l2.sort();

    for(int n : l2)
        cout << n << ", ";
    cout << endl;

    l2.unique();

    for(int n : l2)
        cout << n << ", ";
    cout << endl;
}