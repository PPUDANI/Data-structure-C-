#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> res;
char square(int num)
{
    for ( int i = 0; i < num; i++ )
    {
        res[num].push_back('0');
    }
}
int main()
{
    int num = 1;

    vector<char> v1;
    vector<char> v2;
    v1.push_back('a');
    v1.push_back('b');
    v1.push_back('c');
    v2.push_back('d');
    v2.push_back('e');
    v2.push_back('f');
    res.push_back(v1);
    res.push_back(v2);
    square(num);

    cout << "'0' capacity: " << res[0].capacity() << endl;
    cout << "0: ";
    for(char i : res[0])
    {
        cout << i << " ";
    }
    cout << "\n\n'1' capacity: " << res[1].capacity() << endl;
    cout << "1: ";
    for(char i : res[1])
    {
        cout << i << " ";
    }

    

}