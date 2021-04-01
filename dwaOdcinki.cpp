#include <iostream>
using namespace std;

struct point //structure for storing point
{
    int x, y;
};

point p[4];

short isLeft(int p1, int p2, int p3)
{
    int aX = p[p1].x, bX = p[p2].x, cX = p[p3].x;
    int aY = p[p1].y, bY = p[p2].y, cY = p[p3].y;
    int formula = (aX * bY - bX * aY + bX * cY - cX * bY + cX * aY - aX * cY)/2; //calculating dot product

    if( formula != 0 ) return formula > 0;
    else return -1;
}

bool isDivider(int p1, int p2, int p3, int p4)
{
    if( isLeft(p1, p2, p3) == -1 || isLeft(p1, p2, p4) == -1 )
        return true;
    return isLeft(p1, p2, p3) != isLeft(p1, p2, p4);
}

int main()
{
    for(int i = 0; i < 4; i++)
        cin >> p[i].x >> p[i].y;

    if( isDivider( 0, 1, 2, 3 ) && isDivider( 2, 3, 0, 1 ) )
        cout << "TRUE";
    else
        cout << "FALSE";
}
