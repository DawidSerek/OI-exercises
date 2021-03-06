#include<iostream>
using namespace std;

typedef long long ll;

const int _maxN = 100000;

const ll _lP = 1000000003;
const int _sP = 31;

ll sHash[_maxN];

struct powerStruct
{
    int vLimit = 1000000000;
    long long base[50];

    void setBase( int val )
    {
        base[0] = val;
        for(int i = 1; i < 50; i++)
            base[i] = ( base[i - 1] * base[i - 1] ) % vLimit;
    }
    
    bool bin[50];
    int toBin(int val, int it = 0)
    {
        if( val == 0 ) return it;
        bin[it] = val % 2;
        return toBin( val/2, it + 1 );
    }

    long long request( int exp )
    {
        int n = toBin(exp);
        long long out = 1;
        for(int i = 0; i < n; i++)
            if( bin[i] )
                out *= base[i];
        return out;
    }
};

int hR( int a, int b ) //returns hash value from given range 
{
    powerStruct pow;
    pow.setBase(_sP);

    int out = sHash[a];
    out -= ( sHash[b + 1] * pow.request( b - a + 1 ) ) % _lP;
    if( out < 0 )
        out += _lP;
    return out;
}

int main()
{
    string inp;
    cin >> inp;
    
    int inpS = inp.size() - 1;
    sHash[ inpS ] = int( inp[inpS] );
    for(int i = inpS - 1; i >= 0; i--)
        sHash[i] += (sHash[i + 1] * _sP + inp[i]) % _lP;

    cout << hR( 2,2 );
}