#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

// 문자열의 수가 음수인지 판별하는 함수
bool IsNumNegative ( string &str )
{
    if ( str.front() == '-' )
    {
        return true;
    }
    else 
    {
        return false;
    }
}

//문자열의 순서를 반대로 만드는 함수
string ReverseStr ( string &str )
{
    string revstr = "";

    for ( int i = str.length() - 1; i >= 0; i-- )
    {
        revstr += str[i];
    }

    return revstr;
}

string filltering ( string str, int Maxlen )
{
    str = ReverseStr(str);
    str.resize(Maxlen,'0');
    str = ReverseStr(str);
    return str;
}

//문자열을 부분 연산해주는 함수
long long range_add ( string A, string B, int front, int range )
{
    string sub_A = A.substr(front, range);
    string sub_B = B.substr(front, range);

    sub_A = ReverseStr(sub_A);
    sub_B = ReverseStr(sub_B);

    long long llA = stoll(sub_A);
    long long llB = stoll(sub_B);

    long long llres = llA + llB;
    return llres;
}

// add 연산
string add ( string A, string B )
{
    int Maxlen = A.length();
    int range = 18;

    if ( (Maxlen % range) != 0 )
    {
        Maxlen += range - (Maxlen % range);
    }

    A = filltering(A, Maxlen);
    B = filltering(B, Maxlen);

    A = ReverseStr(A);
    B = ReverseStr(B);
    string res = "";

    int carry = 0;

    for ( int i = 0; i < ( Maxlen / range ); i++ )
    {
        long long llres = range_add(A, B, (range * i), range );

        if ( carry == 1 )
        {
            llres += carry--;
        }

        string strres = to_string(llres);
        strres = ReverseStr(strres);
        
        if ( strres.length() > range )
        {
            carry++;
            strres.pop_back();
        }

        res += strres;
    }

    res = ReverseStr(res);
    return res;
}

//문자열을 부분 연산해주는 함수
long long range_sub ( string A, string B, int front, int range )
{
    string sub_A = A.substr(front, range);
    string sub_B = B.substr(front, range);

    long long llA = stoll(sub_A);
    long long llB = stoll(sub_B);

    long long llres = llA - llB;
    return llres;
}

string sub ( string A, string B )
{
    // 메인 함수에서 큰 쪽을 A에 둠
    int Maxlen = A.length();
    int range = 18;

    // Maxlen을 range의 배수로 바꿈
    if ( (Maxlen % range) != 0 )
    {
        Maxlen += range - (Maxlen % range);
    }

    // 0으로 Maxlen의 길이로 필터링해줌
    A = filltering(A, Maxlen);
    B = filltering(B, Maxlen);
    vector <string> strres;

    for ( int i = 0; i < (Maxlen / range); i++ )
    {
        long long llres = range_sub(A, B, (range * i), range);

        if ( llres < 0 )
        {
            long long befllres = stoll(strres[i-1]) - 1;
            string befstrres = to_string(befllres);

            if ( ((befstrres.length() - 1) < range) )
            {
                befstrres = filltering(befstrres, range);
            }

            strres[i-1] = befstrres;

            long long tenpow = pow(10, range);
            llres += tenpow;
        }

        string str = to_string(llres);

        if ( (i > 0) )
        {
            if ( ((str.length() - 1) < range) )
            {
                str = filltering(str, range);
            }
        }

        strres.push_back(str);

    }
    
    string res = ""; 

    for ( string i : strres )
    {
        res += i;
    }
    
    while ( res[0] == '0' )
    {
        res.erase(0, 1);
    }

    return res;
}

int main()
{
    //18자리수인데 공백 '\0' 포함이 됨.
    string A;
    string B;
    string res = "";

    cin >> A >> B;

    bool Is_A_Nega = IsNumNegative(A);
    bool Is_B_Nega = IsNumNegative(B);

    if ( Is_A_Nega && Is_B_Nega )
    {
        A.erase(0, 1);
        B.erase(0, 1);

        // A의 길이를 기준으로 필터링을 하기위해
        // 만약 B가 더 큰 경우 A와 B를 바꿔서 입력 
        if ( A.length() >= B.length() )
        {
            res = '-' + add(A, B);
        }
        else
        {
            res = '-' + add(B, A);
        }
    }
    else if ( Is_A_Nega == true )
    {
        A.erase(0, 1);

        if ( A.length() > B.length() )
        {
            res = "-" + sub(A, B);
        }
        else if ( B.length() > A.length() )
        {
            res = sub(B, A);
        }
        else
        {
            if ( A > B )
            {
                res = "-" + sub(A, B);
            }
            else if ( A < B )
            {
                res = sub(B, A);
            }
            else
            {
                res = "0";
            }
        }

    }
    else if ( Is_B_Nega == true )
    {
        B.erase(0, 1);

        if ( B.length() > A.length() )
        {
            res = "-" + sub(B, A);
        }
        else if ( B.length() < A.length() )
        {
            res = sub(A, B);
        }
        else
        {
            if ( B > A )
            {
                res = "-" + sub(B, A);
            }
            else if ( B < A )
            {
                res = sub(A, B);
            }
            else
            {
                res = "0";
            }
        }
    }
    else
    {
        if ( A.length() >= B.length() )
        {
            res = add(A, B);
        }
        else
        {
            res = add(B, A);
        }
    }

    cout << res << endl;
}