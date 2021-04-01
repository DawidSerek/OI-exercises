#include <iostream>
#include<algorithm>
using namespace std;

const int _maxN = 100000;
pair<long long , long long> prcs[_maxN];

long long pow(long long a)
{
    return a * a;
}

int fR( int i  )
{
    int dwn = 0, upp = 1000000000;
    int out = 0, mid = (dwn + upp)/2;
    while( dwn < upp )
    {
        mid = (dwn + upp)/2;

        if( pow(mid) < prcs[i].first )
        {
            out = mid + 1;
            dwn = mid + 1;
        }
        else
            upp = mid;
    }
    return out;
}

int main()
{
    int n = _maxN, k = 1;
    //cin >> n >> k;

    int m = 10, p = 1;
    for(int i = 0; i < n; i++)
    {
        //cin >> m >> p;
        long long a = 1, b = 1, maxV = 0;
        for(int j = 0; j < m; j++)
        {
            //cin >> a >> b;
            maxV = max( maxV, pow(a) + pow(b) );
        }
        prcs[i].first = maxV;
        prcs[i].second = p;
    }
    sort( prcs, prcs + n );

    long long out = 0, acc = 0;
    for(int i = 0; i < n; i++)
    {
        acc += prcs[i].second;

        long long r = fR(i);
        long long h = (r + k - 1) / k;
        h--;
        long long cst = (h * (h + 1)) / 2 ;

        out = max( out, acc - cst );
    }

    cout << out;
}
