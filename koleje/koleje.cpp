#include<iostream>
using namespace std;

const int _maxN = 60000;
// const int _tS = 131072;
const int _tS = 16;

struct treeP{
    int a, v;
};

treeP sst[_tS];
pair<int, int> ssst[_tS];

pair<int, int> findSsst( int p )
{
    if( p >= _tS/2 ) 
    {
        ssst[p] = make_pair( p, p );
        return ssst[p];
    }
    ssst[p] = make_pair( findSsst( p*2 ).first, findSsst( p*2 + 1 ).second );
    return ssst[p];
}

void addS( int a, int b, int v, int p = 1 )
{
    if( ssst[p].first >= a && ssst[p].second <= b )
    {
        sst[p].a = v;
        return;
    }
    if( ssst[p*2].second >= a ) addS( a, b, v, p*2 );
    if( ssst[p*2 + 1].first <= b ) addS( a, b, v, p*2 + 1 );
}

int findSS( int a, int b, int p = 1 )
{
    if( ssst[p].first >= a && ssst[p].second <= b )
    {
        sst[p].v = ssst[p].second - ssst[p].first + 1;
        return ;
    }
    if( ssst[p*2].second >= a ) findSS( a, b, p*2 );
    if( ssst[p*2 + 1].first <= b ) findSS( a, b, p*2 + 1 );
}

int main()
{
    int n, k;
    cin >> n >> k;

    findSsst(1);
    for(int i = 1; i < _tS; i++) ssst[i] = make_pair( ssst[i].first - _tS/2 + 1, ssst[i].second - _tS/2 + 1 ); 

    int a, b, c;
    for(int i = 0; i < k; i++)
    {
        cin >> a, b, c; 
    }
    
    addS( 2, 7, 1 );
    int temp = 2;
    for(int i = 1; i < _tS; i++)
    {
        if( i % temp == 0 )
        {
            temp*=2;
            cout << endl;
        }
        cout << sst[i].a << " ";
    }


}