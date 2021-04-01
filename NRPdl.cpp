#include <iostream>
using namespace std;

const int _maxN = 500000;

int t[_maxN];
int NRP[_maxN + 1];

int n, len = 0;

int binS( int v )
{
    int iStart = 0, iEnd = len, iMid, out = 0;
    while( iStart <= iEnd )
    {
        iMid = (iStart + iEnd) / 2;
        if( v <= NRP[ iMid ] )
        {
            iEnd = iMid - 1;
            out = iMid;
        }
        else
            iStart = iMid + 1;
    }
    return out;
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> t[i];

    NRP[0] = t[0];
    for(int i = 1; i < n; i++)
    {
        if( NRP[len] < t[i] )
        {
            len++;
            NRP[len] = t[i];
            continue;
        }

        int lowI = binS( t[i] );
        NRP[lowI] = min( NRP[lowI], t[i] );
    }
    cout << len + 1;
}
