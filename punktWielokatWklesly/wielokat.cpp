#include<iostream>
using namespace std;

const int _maxN = 500000;

struct point
{
    int x,y;
};

int findZeroTrArea(point a, point b)
{
    int rmvC = (a.x * a.y + b.x * b.y + (b.x-a.x)*(a.y-b.y))/2;
    return a.y*b.x-rmvC;
}

int findTr(point a, point b, point c)
{
    int rmv = findZeroTrArea(a, c);
    int out = findZeroTrArea(a, b) + findZeroTrArea(b, c);
    return out - rmv;
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
    for(int i = 0; i < n; i++)
        cin >> q[i].x >> q[i].y;
    
    point a, b,c;
    a.x = 0;
    a.y = 0;
    b.x = 1;
    b.y = 1;
    c.x = 2;
    c.y = 2;
    cout << findTr(a,b,c);

}