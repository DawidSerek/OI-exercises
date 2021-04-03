#include<iostream>
using namespace std;

typedef long long ll;

const int _maxN = 100000;

const ll _lP = 1000000003;
const int _sP = 31;

ll sHash[_maxN];

int hR( int a, int b ) //returns hash value from given range 
{
    int out = sHash[a - 1] - sHash[b];
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
    
    cout << hR( 7,8 );
    

}