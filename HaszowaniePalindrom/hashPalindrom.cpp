#include<iostream>

typedef long long ll;
using namespace std;

const int _maxN = 100000;

struct hashS
{
    const ll _sP = 31;
    const ll _lP = 1000000003;
    int iS;

    ll hashT[_maxN];
    void iniP(string inp)
    {
        iS = inp.size();
        hashT[0] = int( inp[0] );
        for(int i = 1; i < iS; i++)
            hashT[i] = ( hashT[i - 1] * _sP + int( inp[i] ) ) % _lP;
    }
    void iniS(string inp)
    {
        int iS = inp.size();
        hashT[iS-1] = int( inp[iS-1] );
        for(int i = iS-2; i >= 0; i--)
            hashT[i] = ( hashT[i + 1] * _sP + int( inp[i] ) ) % _lP;
    }


    ll pow( int n )
    {
        ll temp = 1;
        for(int i = 0; i < n; i++)
            temp *= _sP;
        return temp;
    }

    ll hP(int a, int b)
    {
        ll out = hashT[b], rmv;

        if( a - 1 >= 0 )
            rmv = ( hashT[a-1] * pow(b + 1 - a) ) % _lP;
        else
            rmv = 0;

        out -= rmv;
        if(out < 0)
            out += _lP;

        return out;
    }
    ll hS(int a, int b, int iS)
    {
        ll out = hashT[a], rmv;
        
        if( b + 1 < iS )
            rmv = ( hashT[ b+1 ] * pow(b + 1 - a) ) % _lP;
        else
            rmv = 0;
        
        out -= rmv;
        if(out < 0)
            out += _lP;

        return out;
    }
};


int main()
{
    string inp;
    cin >> inp;

    hashS pref, suf;
    pref.iniP(inp);
    suf.iniS(inp);

    int out = 0;
    for(int i = 0; i < inp.size(); i++)
    {
        int left = i - 1, right = i + 1;
        while( left >= 0 && right < inp.size() )
        {
            if( pref.hP(left,i) == suf.hS(i,right, inp.size() ) )
                out++;
            left--;
            right++;
        }
        left = i - 1, right = i;
        while( left >= 0 && right < inp.size() )
        {
            if( pref.hP(left,i - 1) == suf.hS(i,right, inp.size() ) )
                out++;
            left--;
            right++;
        }
    }
    cout << out;
    return 0;
}