#include<iostream>
using namespace std;

typedef long long ll;
const int _maxN = 15;

struct hashS
{
    const ll _sP = 31;
    const ll _lP = 1000000003;

    ll hashT[_maxN];
    ll pow[_maxN];
    string inp;

    void iniPow()
    {
        pow[0] = 1;
        for(int i = 1; i < _maxN; i++)
            pow[i] = (pow[i-1] * _sP) % _lP;
    }

    void iniP()
    {
        int n = inp.size() - 1;
        hashT[n] = int( inp[n] );
        for(int i = n - 1; i >= 0; i--)
            hashT[i] = ( hashT[i + 1] * _sP + int(inp[i]) ) % _lP;
        iniPow();
    }
    void iniS()
    {
        int n = inp.size();
        hashT[0] = int( inp[0] );
        for(int i = 1; i < n; i++)
            hashT[i] = ( hashT[i - 1] * _sP + int(inp[i]) ) % _lP;
        iniPow();
    }

    int findPR()
    {
        
    }


};

int main()
{
    string inp;
    cin >> inp;

    hashS prefix;
    prefix.inp = inp;
    prefix.iniP();
    
    hashS sufix;
    sufix.inp = inp;
    sufix.iniS();



}