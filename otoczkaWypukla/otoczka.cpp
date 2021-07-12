#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int _maxN = 10;

struct point
{
    int x, y;
};
point inp[_maxN];

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

int main()
{

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> inp[i].x >> inp[i].y;

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


    for(int i = 0; i < conH.size(); i++)
        cout << conH[i].x << " " << conH[i].y << "|";
    return 0;
}