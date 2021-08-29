#include<iostream>
#include<map>
using namespace std;

const int _maxN = 1000000;

int pre[_maxN];
int ref[_maxN * 2];

#define valI ref[ pre[i] + _maxN ]

int main()
{
    string inp;
    cin >> inp;

    for(int i = 0; i < _maxN * 2; i++)
        ref[i] = inp.size() - 1;
    for(int i = 0; i < inp.size(); i++)
    {
        if( inp[i] == inp[0] ) 
            pre[i] = pre[ max( i-1, 0 ) ] + 1;
        else 
            pre[i] = pre[ max( i-1, 0 ) ] - 1;
        valI = min( valI, i );
    }

    int out = 0;
    for(int i = 0; i < inp.size(); i++)
    {
        if( pre[i] == 0 ) out = max( out, i + 1 );
        out = max( out, i - valI );
    }
    cout << out;
    return 0;
}