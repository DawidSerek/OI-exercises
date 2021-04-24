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
    vector <ll> v;
    vector <ll> out;
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
    int out = 0, yIt = y.out.size() - 1;
    for(int xIt = 0; xIt < x.out.size(); xIt++)
    {
        while( x.out[xIt] * y.out[yIt] > mid && yIt >= 0 )
            yIt--;
        out += yIt + 1;
    }
    return out;
}

int main()
{
    cin >> a >> b >> n >> k;
    
    convInp x, y;
    ll temp;
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

    for(int z = 16; z > 0; z--)
    {
        cout << "["<<z<<"]" << " ";
        ll beg = 0, end = a * b, mid, out = a*b;
        while(beg <= end)
        {
            mid = (beg+end)/2;
            if( findK(x,y,mid) <= (n+1) * (n+1) - z )
            {
                beg = mid + 1;
                out = mid;
            }
            else
                end = mid - 1;
        }
        cout << out << " ";
    }
}