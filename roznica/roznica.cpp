#include<iostream>
#include<vector>
using namespace std;

const int _alphS = 36;

vector <int> charApp[_alphS];

int CSMS(int a, int b)
{
    if( a == b ) return 0;

    int n1 = charApp[a].size(), n2 = charApp[b].size();
    int it1 = 0, it2 = 0;
    int temp = -1, tOut = 0, out = 0;
    bool isOk = false;
    while( it1 < n1 && it2 < n2 )
    {
        temp = min( charApp[a][it1], charApp[b][it2] );
        if( charApp[a][it1] == temp )
        {
            it1++;
            tOut++;
        } 
        else if( charApp[b][it2] == temp )
        {
            it2++;
            isOk = tOut - 1 >= 0;
            tOut = max( tOut - 1, 0 );
        }
        if( it2 >= n2 ) tOut += n1 - it1;
        out = max( out, tOut - !isOk );
    }
    return out;
}

int charId( char a )
{
    if( a >= 'a' )
    {
        a -= 'a';
        a += 10;
    } 
    else a -= '0';
    return int(a);
}

int main()
{
    int n;
    string inp;
    cin >> n >> inp;

    for(int i = 0; i < n; i++)
        charApp[ charId(inp[i]) ].push_back(i);

    int out = 0;
    for(int i = 0; i < _alphS; i++)
    {
        for(int j = 0; j < _alphS; j++)
            out = max( out, CSMS( i, j ) );
    }
    cout << out;
    return 0;
}