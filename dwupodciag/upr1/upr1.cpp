#include<iostream>
#include<vector>
#include<string>
using namespace std;


const int _alphS = 36;
bool vis[_alphS];

int cnv( char a )
{
    int nmb = int( a );
    if( nmb >= 97 ) nmb -= 87;
    else nmb -= 48;
    return nmb;
}

int main()
{
    string inp;
    cin >> inp;

    int lstV = 0, cnt = 0, nowP = 0, out = 0;
    for(int i = 0; i < inp.size(); i++)
    {
        int crrCh = cnv( inp[i] );
        if( !vis[ crrCh ] )
        {
            vis[ crrCh ] = true;
            cnt++;
        }
        if( cnt == 3 )
        {   
            nowP = lstV;
            vis[ cnv( inp[ lstV-1 ] ) ] = false;
            cnt--;
        }
        if( cnv( inp[ max(i-1, 0) ] ) != inp[i] ) lstV = i;
        out = max( out, i - nowP + 1 );
    }
    cout << out;
    return 0;
}