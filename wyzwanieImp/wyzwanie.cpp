#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

const int _maxN = 1000000;

#define distance pow(t[i].y - t[i+j].y, 2) + pow(t[i].x - t[i+j].x, 2)

struct point{
    ll x, y;
};
point t[_maxN];

bool compX( point a, point b )
{
    if( a.x > b.x ) 
        return false;
    return true;
}
bool compY( point a, point b )
{
    if( a.y < b.y ) 
        return false;
    return true;
}

ll bstDiff(int beg, int end)
{
    ll out = 1000000000000000000;
    for(int i = beg; i < end; i++)
        out = min( out, abs(t[i].y - t[i+1].y) );
    return out * out;
}

ll solveSec( int beg, int end )
{
    if( beg == end ) return -1;
    
    int div = t[beg].x + t[end].x;
    //find indexes where division point starts and ends for next recursive function iterations
    int divI = end;
    int temp = 0;
    for(int i = beg; i <= end; i++)
        if( t[i].x*2 > div )
        {
            divI = i;
            break;
        }
        else if( t[i].x*2 == div ) temp++;
    if( temp == end - beg + 1 ) return bstDiff(beg, end);

    ll left = -2, right = -2;
    if( divI - 1 >= beg ) left = solveSec( beg, divI - 1 ); 
    if( divI <= end ) right = solveSec( divI, end ); 

    ll out = min( left, right );
    if( left < 0 || right < 0 ) out = max(left, right);
    if( out < 0 ) out = 1000000000000000;

    vector <point> outQ;
    for(int i = beg; i <= end; i++)
        if( div - out*2 <= t[i].x*2 && t[i].x*2 <= div + out*2 )
            outQ.push_back( t[i] );
    sort( outQ.begin(), outQ.end(), compY );

    for(int i = 0; i < outQ.size(); i++)
        for(int j = 1; distance < out && i+j < outQ.size(); j++)
            out = distance;
    return out;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> t[i].x >> t[i].y;

    sort( t, t+n, compX );

    cout << sqrt( double( solveSec(0, n-1) ) );
}