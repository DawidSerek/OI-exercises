#include <iostream>
using namespace std;

struct point //structure for storing point
{
    int x, y;
};

int qC(int i) //quickly repairs overflow, if present
{
    if( i < 2 ) return i + 1;
    return 0;
}

point p[4];
int main()
{
    for(int i = 0; i < 4; i++)
        cin >> p[i].x >> p[i].y;

    int cntr = 0. cntr2;
    for(int i = 0; i < 3; i++)
    {
        int aX = p[i].x, bX = p[ qC(i) ].x, cX = p[3].x;
        int aY = p[i].y, bY = p[ qC(i) ].y, cY = p[3].y;
        int formula = (aX * bY - bX * aY + bX * cY - cX * bY + cX * aY - aX * cY)/2; //calculating dot product
        if( formula < 0 ) cntr++;
		if( formula > 0 ) cntr2++;
    }

    if( cntr == 3 || cntr2 == 3 )
        cout << "TRUE";
    else
        cout << "FALSE";
}
