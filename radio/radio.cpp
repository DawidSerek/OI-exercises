#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int _maxN = 20001;

struct point
{
    int x, y;
    int i;
};
point inp[_maxN];
bool isOut[_maxN];

int vProd0( point a, point b )
{
    int tr1 = a.x * a.y;
    int tr2 = b.x * b.y;
    int tr3 = (b.x-a.x) * (a.y-b.y);
    return b.x * a.y * 2 - ( tr1 + tr2 + tr3 );
}

int vProd( point a, point b, point c )
{
    int tr1 = vProd0(a, b);
    int tr2 = vProd0(b, c);
    int rmv = vProd0(a, c);
    return tr1 + tr2 - rmv;
}

bool comp(point a, point b)
{
    if(a.x > b.x) return false;
    return true;
}

ll genDis( point a, point b )
{
    return abs(a.y - b.y) * abs(a.y - b.y) + abs(a.x - b.x) * abs(a.x - b.x);
}

bool isRec( point a, point b, point c )
{
    ll dis[3] = { genDis(a,b), genDis(b,c), genDis(a,c) };
    if( dis[0] + dis[1] >= dis[2] )
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> inp[i].x >> inp[i].y;
        inp[i].i = i + 1;
    }

    sort(inp, inp+n, comp);

    vector <point> conH;
    for(int i = 0; i < n; i++)
    {
        for(int p = conH.size() - 1; p >= 1 && vProd( conH[p-1], conH[p], inp[i] ) < 0; p--)
            conH.pop_back();
        conH.push_back(inp[i]);
    }
    for(int i = n-2; i >= 1; i--)
    {
        for(int p = conH.size() - 1; p >= 1 && vProd( conH[p-1], conH[p], inp[i] ) < 0; p--)
            conH.pop_back();
        conH.push_back(inp[i]);
    }
    for(int p = conH.size() - 1; p >= 1 && vProd( conH[p-1], conH[p], inp[0] ) < 0; p--)
        conH.pop_back();

    int cnt = 0;
    for(int i = 0; i < conH.size(); i++)
    {
        point a;
        if( i == 0 )
            a = conH[ conH.size()-1 ];
        else
            a = conH[ i-1 ];
        point b = conH[i];
        point c = conH[ (i+1) % n ];

        if( isRec(a,b,c) )
        {
            cnt++;
            isOut[ b.i ] = true;
        }
    }
    cout << cnt << endl;
    for(int i = 0; i < _maxN; i++)
        if( isOut[i] )
            cout << i << endl;
    return 0;
}
