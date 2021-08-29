#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int _maxN = 1000000;
const int _alphS = 36;

int pre[_maxN];
int ref[_maxN * 2];
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
    inp = inp + '#';

    int lstP = 0, nowP = 0, cnt = 0, out = 0;
    for(int i = 0; i < _maxN*2; i++)
        ref[i] = inp.size();
    for(int i = 0; i < inp.size(); i++)
    {
        if( !vis[cnv(inp[i])] )
        {
            vis[cnv(inp[i])] = true;
            cnt++;
        }
        if( cnt == 3 )
        {
            pre[0] = 0;
            for(int j = 0; j < i - nowP; j++)
            {
                if( inp[nowP] == inp[j + nowP] ) 
                    pre[j] = pre[ max(0, j-1) ] + 1; 
                else 
                    pre[j] = pre[ max(0, j-1) ] - 1;

                if( pre[j] != 0 )
                {
                    ref[ pre[j] + _maxN ] = min( ref[ pre[j] + _maxN ], j );
                    out = max( out, j - ref[ pre[j] + _maxN ] );
                }
                else
                    out = max( out, j + 1 );
            }
            for(int j = 0; j < i - nowP; j++) 
                ref[ pre[j] + _maxN ] = inp.size();
                
            vis[ cnv( inp[lstP-1] ) ] = false;
            cnt--;
            nowP = lstP;
        }
        if( inp[ max( i-1, 0 ) ] != inp[i] ) lstP = i;
    }
    cout << out;
    return 0;
}