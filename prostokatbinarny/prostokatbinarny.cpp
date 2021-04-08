#include <iostream>
#include<bitset>
using namespace std;

const int _maxN = 3000;
const int _compN = 80;

unsigned int inp[_compN][_maxN];

void tBit(int bit, int h) //turns on requested bit in ,,input"
{
    int x = inp[bit/32][h];

    x = x | (1 << bit%32);

    inp[bit/32][h] = x;
}

bool chBit(unsigned int bit, int h)
{
    unsigned int x = inp[ bit/32 ][h];
    int comp = 1 << (bit % 32);

    if( ( x & comp ) != 0 )
        return true;
    else
        return false;
}

int fLeft(int r1, int r2)
{
    for(int i = 0; i < _compN; i++) //from every set
        if( (inp[i][r1] & inp[i][r2]) > 0 ) //if set checks out
            for(int j = 0; j < 32; j++ ) //check every bit from left
                if( chBit(j + i * 32, r1) && chBit(j + i * 32, r2) ) //if bits are checking out
                    return j + i * 32; //return position
    return 2000000;
}

int fRight(int r1, int r2)
{
    for(int i = _compN - 1; i >= 0; i--) //from every set
        if( (inp[i][r1] & inp[i][r2]) > 0 ) //if set checks out
            for(int j = 31; j >= 0; j-- ) //check every bit from right
                if( chBit(j + i * 32, r1) && chBit(j + i * 32, r2) ) //if bit checks out
                    return j + i * 32; //return position
    return 0;
}

int main()
{
    int n;
    cin >> n;

    for(int y = 0; y < n; y++)
        for(int x = 0; x < n; x++)
        {
            int a;
            cin >> a;
            if( a == 1 )
                tBit( x, y );
        }

    int maxV = 0, left, right;
    for( int r1 = 0; r1 < n; r1++ )
        for( int r2 = r1 + 1; r2 < n; r2++ )
        {
            left = fLeft(r1,r2) ;
            right = fRight(r1, r2) + 1;

            maxV = max( maxV, (r2 - r1 + 1)*(right - left) );
        }
    cout << maxV;
}
