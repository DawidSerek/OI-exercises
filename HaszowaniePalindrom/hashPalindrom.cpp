#include<iostream>
using namespace std;

typedef long long ll;
const int _maxN = 100000;

struct hashS
{
    const ll _sP = 31;
    const ll _lP = 1000000003;

    ll hashT[_maxN];
    ll pow[_maxN];
    string inp;
    bool isP;

    void iniPow()
    {
       
        pow[0] = 1;
        for(int i = 1; i < _maxN; i++)
            pow[i] = (pow[i-1] * _sP) % _lP;
    }

    void iniS(string txt)
    {
        inp = txt;
        isP = false;
        int n = inp.size() - 1;
        hashT[n] = int( inp[n] );
        for(int i = n - 1; i >= 0; i--)
            hashT[i] = ( hashT[i + 1] * _sP + int(inp[i]) ) % _lP;
        iniPow();
    }
    void iniP(string txt)
    {
        inp = txt;
        isP = true;
        int n = inp.size();
        hashT[0] = int( inp[0] );
        for(int i = 1; i < n; i++)
            hashT[i] = ( hashT[i - 1] * _sP + int(inp[i]) ) % _lP;
        iniPow();
    }

    int findR(int a, int b)
    {
        if( !isP )
        {
            ll rmv = (hashT[b + 1] * pow[b + 1 - a]) % _lP;
            if( b + 1 >= inp.size() ) rmv = 0;
            ll out = hashT[a] - rmv;
            if( out < 0 )
                out += _lP;
            return out;
        }
        else
        {
            ll rmv = 0;
            if( a - 1 >= 0 ) rmv = (hashT[a - 1] * pow[b + 1 - a]) % _lP;
            ll out = hashT[b] - rmv;
            if( out < 0 )
                out += _lP;
            return out;
        }
    }
};



int binS(int i, bool isOdd, string inp, struct hashS *pre, struct hashS *suf)
{
    int start = 1, end = min( i, int(inp.size() - i) ), mid, tOut = 0;
    while( start <= end )
    {
        mid = (start + end) / 2;
        if( pre->findR( i - mid, i - 1 + isOdd) == suf->findR(i, i + mid - 1 + isOdd) )
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

    hashS pre, suf;
    pre.iniP(inp);
    suf.iniS(inp);

    int out = 0;
    /*
    for(int i = 1; i < inp.size(); i++)
    {
        out += binS(i, 1, inp, &pre, &suf);
        out += binS(i, 0, inp, &pre, &suf);
    }/**/
    cout << out;
}