#include <iostream>
#include <vector>
using namespace std;

void square(vector<vector<char>> &res, int num, int y, int x, char c)
{
    if(num == 1)
    {
        res[y][x] = c;
    }
    else
    {
        int count = 0;
        for ( int i = y; i < y + num; i += num/3 )
        {
            for ( int j = x; j < x + num; j += num/3 )
            {
                if ( count == 4 )
                {
                    square(res, num/3, i, j, ' ');
                }
                else
                {
                    square(res, num/3, i, j, c);
                }
                count++;
            }
            
        }
    }

}

int main()
{
    int num = 27;
    vector<vector<char>> res(num, vector<char>(num));

    square(res, num, 0, 0, '*');

    //res 출력
    for(int j = 0; j < num; j++)
    {
        for(char i : res[j])
        {
            cout << i;
        }
        cout << endl;
    }
}