#include<iostream>
using namespace std;

const int _maxN = 20;

int KMP[_maxN];

void checkSec(int beg, string str)
{
    string newStr = "", key = "";
    for(int i = 0; i < beg; i++)
        key.push_back( str[i] );
    for(int i = beg; i < str.size(); i++)
        newStr.push_back( str[i] );
    newStr = key + "$" + newStr;

    for(int i = 1; i < newStr.size(); i++)
    {
        int temp = KMP[i-1];
        while( newStr[temp] != newStr[i] && temp > 0 )
            temp = KMP[temp];
        if( newStr[temp] == newStr[i] )
            temp++;
        KMP[i] = temp;
    }

    for(int i = 0; i < newStr.size(); i++)
        cout << newStr[i] << " ";
    cout << endl;
    for(int i = 0; i < newStr.size(); i++)
        if( KMP[i] >= key.size() )
            cout << "1 ";
        else
            cout << "0 ";
    cout << endl;

    for(int i = 0; i < _maxN; i++)
        KMP[i] = 0;

}

int main()
{
    string inp;
    cin >> inp;

    for(int i = 1; i < inp.size(); i ++)
    {
        checkSec(i, inp);
    }
    

}