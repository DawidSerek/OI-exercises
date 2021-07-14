#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define cHS cH.size()

typedef long long ll;

const int _maxN = 200000;

struct point{
    ll x, y;
};
point t[_maxN];

ll vPO( point a, point b )
{
    ll tr1 = a.x * a.y;
    ll tr2 = b.x * b.y;
    ll tr3 = (b.x-a.x) * (a.y - b.y);
    ll base = a.y * b.x * 2;
    return base - ( tr1 + tr2 + tr3 );
}

ll vPC( point a, point b, point c )
{
    ll tr1 = vPO(a, b);
    ll tr2 = vPO(b, c);
    ll rmv = vPO(a, c);
    return tr1 + tr2 - rmv;
}

bool comp( point a, point b )
{
    return vPO(a, b) >= 0;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> t[i].x >> t[i].y;

    point minXP;
    minXP.x = 10000000000;
    for(int i = 0; i < n; i++)
        if( t[i].x < minXP.x )
            minXP = t[i];
    for(int i = 0; i < n; i++)
    {
        t[i].x -= minXP.x;
        t[i].y -= minXP.y;
    }

    sort(t, t+n, comp);

    vector <point> cH;
    for(int i = 0; i < n; i++)
    {
        while( cHS >= 2 && vPC( cH[cHS-2], cH[cHS-1], t[i] ) < 0 )
            cH.pop_back();
        cH.push_back(t[i]);
    }

    for(int i = 0; i < cHS; i++)
        cout << cH[i].x + minXP.x << " " << cH[i].y + minXP.y << endl;
    return 0;
}