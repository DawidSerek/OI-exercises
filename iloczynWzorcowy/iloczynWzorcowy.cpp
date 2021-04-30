#include<iostream>
using namespace std;

typedef long long ll;

const int _maxN = 1000000;
const ll _sP = 31;
const ll _lP = 1000000003;

ll hashT[_maxN];
ll powT[_maxN];
ll cnt[_maxN];

ll hR(int a, int b)
{
    ll out = hashT[b], rmv = 0;
    if( a > 0 ) rmv = (hashT[a-1] * powT[b - a]) % _lP;
    if( out - rmv < 0 ) return out - rmv + _lP;
    return out - rmv;
}


int main()
{
    string inp;
    cin >> inp;
    int n = inp.size();

    hashT[0] = int(inp[0]);
    powT[0] = _sP;
    for(int i = 1; i < n; i++)
    {
        hashT[i] = ( hashT[i-1] * _sP + int(inp[i]) ) % _lP;
        powT[i] = (powT[i-1] * _sP) % _lP;
    }
    
    ll rslt = 0, sumSuf = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        ll beg = 0, end = n, mid, out = 0;
        while( beg <= end )
        {
            mid = (beg+end)/2;
            if( hR(0, 0 + mid) == hR(i, i + mid) && 0 + mid < i && i + mid < n )
            {
                beg = mid + 1;
                out = mid + 1;
            }
            else
                end = mid - 1;
        }
        cnt[out]++;
        sumSuf += cnt[i+1];
        rslt = max( rslt, sumSuf * (i+1) );
    }
    cout << endl << rslt;
}