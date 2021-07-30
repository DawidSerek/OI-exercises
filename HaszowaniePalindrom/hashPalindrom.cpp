#include<iostream>
using namespace std;

typedef long long ll;
const int _maxN = 20;
const ll _sP = 31;
const ll _lP = 1000000003;

ll hashT[_maxN][2];
ll powT[_maxN];
string inp;
bool isP;

void iniPow()
{
    powT[0] = 1;
    for(int i = 1; i < _maxN; i++)
        powT[i] = (powT[i-1] * _sP) % _lP;
}

void iniS(string txt)
{
    inp = txt;
    int n = inp.size() - 1;
    hashT[n][0] = int( inp[n] );
    for(int i = n - 1; i >= 0; i--)
        hashT[i][0] = ( hashT[i + 1][0] * _sP + int(inp[i]) ) % _lP;
    
}
void iniP(string txt)
{
    inp = txt;
    int n = inp.size();
    hashT[0][1] = int( inp[0] );
    for(int i = 1; i < n; i++)
        hashT[i][1] = ( hashT[i - 1][1] * _sP + int(inp[i]) ) % _lP;
}

int findR(int a, int b, int isP)
{
    if( !isP )
    {
        ll rmv = (hashT[b + 1][0] * powT[b + 1 - a]) % _lP;
        if( b + 1 >= inp.size() ) rmv = 0;
        ll out = hashT[a][0] - rmv;
        if( out < 0 )
            out += _lP;
        return out;
    }
    else
    {
        ll rmv = 0;
        if( a - 1 >= 0 ) rmv = (hashT[a - 1][1] * powT[b + 1 - a]) % _lP;
        ll out = hashT[b][1] - rmv;
        if( out < 0 )
            out += _lP;
        return out;
    }
}

int binS(int i, bool isOdd, string inp)
{
    int start = 1, end = min( i, int(inp.size() - i) ), mid, tOut = 0;
    while( start <= end )
    {
        mid = (start + end) / 2;
        if( findR( i - mid, i - 1 + isOdd, 1) == findR(i, i + mid - 1 + isOdd, 0) )
        {
            tOut = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return tOut;
}

int main()
{
    string inp;
    cin >> inp;

    iniPow();
    iniP(inp);
    iniS(inp);

    ll out = 0;
    for(int i = 1; i < inp.size(); i++)
    {
        out += binS(i, 1, inp);
        out += binS(i, 0, inp);
    }
    cout << out;
}