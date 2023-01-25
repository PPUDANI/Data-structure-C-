#include <iostream>
#include <vector>
using namespace std;

void square(vector<vector<string>> &res, int num, int y, int x, string c)
{
    if(num == 1)
    {
        res[y][x] = c;
    }
    else
    {
        // 3 X 3 = 9 즉 아홉 번 반복인 for loop 에서 다섯 번째는 '*' 대신 공백을 매개변수로 변경
        // 
        int count = 0; 
        for ( int i = y; i < y + num; i += num/3 )
        {
            for ( int j = x; j < x + num; j += num/3 )
            {
                if ( count == 4 )
                {
                    square(res, num/3, i, j, "  ");
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
    int num;
    cin >> num;
    vector<vector<string>> res(num, vector<string>(num));

    square(res, num, 0, 0, "▩ ");

    //res 출력
    for(int j = 0; j < num; j++)
    {
        for(string i : res[j])
        {
            cout << i;
        }
        cout << endl;
        
    }
}