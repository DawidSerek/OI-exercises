#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

const int _maxN = 200000;
ll a, b, n, k;

int x[_maxN];
int y[_maxN];

struct convInp
{
    vector <int> v;
    vector <int> out;
    void ini(int n, int len)
    {
        out.push_back( v[0] );
        for(int i = 0; i < n - 1; i++)
            out.push_back( v[i+1] - v[i] );
        out.push_back( len - v[n-1] );
        sort(out.begin(), out.end());
    }

};

int findK(convInp x, convInp y, int mid)
{
    int yIt = 0, out = 0;
    for(int xIt = 0; xIt <= n; xIt++)
    {
        while( x.out[xIt] * y.out[n - yIt] > mid && yIt <= n )
            yIt++;
        out += yIt;
    }
    return out;
}

int main()
{
    cin >> a >> b >> n >> k;
    
    convInp x, y;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        x.v.push_back(temp);
    }
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        y.v.push_back(temp);
    }
    x.ini(n, a);
    y.ini(n, b);

    ll beg = 0, end = a * b, mid, out = a*b;
    while(beg < end)
    {
        mid = (beg+end)/2;
        if( findK(x,y,mid) >= k - 1 )
        {
            beg = mid;
            out = mid;
        }
        else
            end = mid - 1;
    }
    cout << out;
}