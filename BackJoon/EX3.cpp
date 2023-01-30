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
        // for loop를 할때마다 num/3을 더해주면서 입력값이 3의 배수인 걸 이용하여
        // 무조건 9번 루프를 돌 수 있게 한다.(이 패턴의 근본은 9조각으로 나누는 것)
        // 해당 값이 9칸의 패턴으로 나누는 기준 좌표가 된다.

        // 결국 9 X 9 X 9 = 729(27 X 27) 이 되는 것이다.

        // 여기서 i는 매개변수의 y, j는 매개변수의 x로 시작한다.
        // 결국 해당 기준값부터 시작을 하므로 벡터의 주소 전부를 한번씩 방문한다.

        // 만약 num이 1이면 해당 주소에 매개변수 c로 채우는데
        // 여기서 count 변수를 사용하여 9번의 루프 중 5번째 의 경우는
        // square() 함수의 매개변수 c에 공백으로 바꿔줌으로써 해당 주소에는 공백으로 채워진다.

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
    int num;
    cin >> num;
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