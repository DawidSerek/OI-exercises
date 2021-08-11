#include<iostream>
using namespace std;

const int _alphS = 36;

int oP[_alphS];
int cnt[_alphS];

int charVal( char a )
{
    int val;
    if( a >= 'a' ) val = a - 'a' + 10;
    else val = a - '0';
    return val;
}

int main()
{
    string inp;
    cin >> inp;
    int n = inp.size();

    for(int i = 0; i < n; i++)
    {
        int val = charVal(inp[i]);
        cnt[ val ]++;
        if( oP[val] == 0 ) oP[val] = i + 1;
    }

    for(int i = 0; i < _alphS; i++)
        if( cnt[i] != 0 )
            if( i >= 10 )
                cout << char( 'a' + i - 10 ) << ":" << cnt[i] << endl;
            else
                cout << char( '0' + i ) << ":" << cnt[i] << endl;

    // int out = 0;
    // for(int i = 0; i < n; i++)
    // {
    //     cnt[ charVal(inp[i]) ]++;
    //     int preDel = 0;
    //     for(int j = 0; j < _alphS; j++)
    //         if( cnt[j] % 2 == 1 ) preDel = max( preDel, oP[j] );
    //     out = max( out, i + 1 - preDel );
    // }
    // cout << out;
}