#include<iostream>
#include<vector>
#include<map>
using namespace std;

const int _maxN = 1000000;
const int _logN = 20 + 2;

vector <int> KMR[_logN];
map < pair<int, int>, int> KMRR;
int pow[_logN];

#define SHIFT ( 1 << (i-1) )

bool compKMR( int a, int b, int c, int d )
{
    if( a - b != c - d ) return a - b > c - d;
    int diff = b - a + 1;

    int beg = 0, end = _logN, mid, out;
    while( beg <= end )
    {
        mid = (beg + end)/2;
        if( pow[mid] * 2 < diff ) beg = mid + 1;
        if( pow[mid] > diff ) end = mid - 1;
        if( pow[mid] * 2 >= diff && pow[mid] <= diff )
        {
            out = mid;
            break;
        }
    }
    return KMR[out][a] == KMR[out][c] &&  KMR[out][ b - pow[out] + 1 ] == KMR[out][ d - pow[out] + 1 ];
}

int main()
{
    pow[0] = 1;
    for(int i = 1; i < _logN; i++)
        pow[i] = pow[i-1] * 2;

    string inp;
    cin >> inp;
    int n = inp.size();

    int maxV = -1;
    for(int i = 0; i < n; i++)
    {
        int charV = inp[i] - 'a';
        KMR[0].push_back( charV );
        maxV = max( maxV, charV );
    }
    
    for(int i = 1; i < _logN; i++)
        for(int j = 0; j + SHIFT < KMR[i-1].size(); j ++ )
        {
            pair<int, int> crrPair = make_pair( KMR[i-1][j], KMR[i-1][ j + SHIFT ] );
            if( KMRR[crrPair] == 0 )
            {
                maxV++;
                KMRR[crrPair] = maxV;
            }
            KMR[i].push_back( KMRR[crrPair] );
        }
    cout << compKMR( 1, 2, 6, 7 );
}