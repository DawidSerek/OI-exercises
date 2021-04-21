#include<iostream>
using namespace std;

typedef long long ll;
const int _maxN = 500000;

struct point
{
    int x,y;
};

ll findZeroTrArea(point a, point b)
{
    ll rmvC = (a.x * a.y + b.x * b.y + (b.x-a.x)*(a.y-b.y))/2;
    return a.y*b.x-rmvC;
}
ll isR(point a, point b, point c)
{
    ll rmv = findZeroTrArea(a, c);
    ll out = findZeroTrArea(a, b) + findZeroTrArea(b, c);
    out -= rmv;
    if( out != 0 ) return out > 0;
    return -1;
}
bool isDiv(point a, point b, point c, point d)
{
    if( isR(a,b,c) == -1 || isR(a,b,d) == -1 )
        return true;
    return isR(a,b,c) != isR(a,b,d);
}
bool isCross(point a, point b, point c, point d)
{
    return isDiv(a,b,c,d) && isDiv(c,d,a,b);
}

point inp[_maxN];
point q[_maxN];
int main()
{
    int n, z;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> inp[i].x >> inp[i].y;
    cin >> z;
    for(int i = 0; i < z; i++)
        cin >> q[i].x >> q[i].y;
    
    for(int i = 0; i < z; i++)
    {
        point half;
        half.x = q[i].x + 100000000;
        half.y = q[i].y + 1;
        int temp = 0;
        for(int j = 0; j < n; j++)
            if( !isDiv( inp[j], inp[(j+1)%n], q[i], q[i] ) )
                temp += isCross( q[i], half, inp[j], inp[ (j+1)%n ] );
            else
            {
                temp = 0;
                break;
            }
        if(temp % 2 == 1) cout << "TAK";
        else cout << "NIE";
        cout << endl;
    }
}