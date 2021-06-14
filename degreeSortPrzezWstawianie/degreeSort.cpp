#include<iostream>
#include<algorithm>
using namespace std;

const int _maxN = 500000;

struct point
{
    int x, y;
};

bool isR(point a, point b)
{
    int base = a.y * b.x;
    int rmv1 = a.x * a.y / 2;
    int rmv2 = b.x * b.y / 2;
    int rmv3 = (b.x-a.x) * (a.y-b.y) / 2;
    return ( base - (rmv1 + rmv2 + rmv3) ) >= 0;
}

point inp[_maxN];

int main()
{
    int n;
    cin >> n;

    int a, b;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        inp[i].x = a; 
        inp[i].y = b;
    }

    sort( inp, inp + n, isR );

    // for(int i = 0; i < n; i++)
    //     for(int j = i; j < n; j++)
    //         if( !isR( inp[i], inp[j] ) )
    //             swap( inp[i], inp[j] );

    for(int i = 0; i < n; i++)
        cout << inp[i].x << " " << inp[i].y << endl;

}