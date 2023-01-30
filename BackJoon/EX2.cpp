#include <iostream>
#include <string>
using namespace std;


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


string ReverseStr ( string str )
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
    return str;
}


string add ( string A, string B )
{
    string res = "";
    int Maxlen = A.length();
    int carry = 0;

    A = ReverseStr(A);
    B = filltering(B, Maxlen);

    for ( int i = 0; i < Maxlen; i++ )
    {
        int i_A = (int)A[i] - 48;
        int i_B = (int)B[i] - 48;
        int i_res;

        if ( carry == 0 )
        {
            i_res = i_A + i_B;
        }
        else
        {
            i_res = i_A + i_B + carry;
            carry--;
        }
        
        if ( i_res >= 10 )
        {
            i_res -= 10;
            carry++;
        }

        res += to_string(i_res);
    }
    if ( carry == 1 )
    {
        res += "1";
    }

    res = ReverseStr(res);
    return res;
}


string sub ( string A, string B )
{
    string res = "";
    int Maxlen = A.length();
    int carry = 0;

    A = ReverseStr(A);
    B = filltering(B, Maxlen);

    for ( int i = 0; i < Maxlen; i++ )
    {
        int i_A = (int)A[i] - 48;
        int i_B = (int)B[i] - 48;
        int i_res;

        if ( carry == 0 )
        {
            i_res = i_A - i_B;
        }
        else
        {
            i_res = i_A - i_B - carry;
            carry--;
        }

        if ( i_res < 0 )
        {
            i_res += 10;
            carry++;
        }

        res += to_string(i_res);
    }

    res = ReverseStr(res);

    while ( res[0] == '0' )
    {
        res.erase(0, 1);
    }

    return res;
}


int main()
{
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
