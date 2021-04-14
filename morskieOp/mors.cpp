#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

const int _maxN = 20;
const int _maxK = 1000000;

vector <int> nei[_maxN + 1];
bool vis[_maxN + 1][2];
int path[_maxN + 1][2];

pair<int, pair<int, int> > inpQ[_maxK]; 
int inp[_maxN][3];
map < pair<int, int>, pair<int, int> > out;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int a, b, c;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }

    for(int i = 0; i < k; i++)
    {
        cin >> inp[i][0] >> inp[i][1] >> inp[i][2];
        inpQ[i].first = inp[i][0];
        inpQ[i].second.first = inp[i][1];
        inpQ[i].second.second = inp[i][2];
        out[ make_pair(inpQ[i].first, inpQ[i].second.first) ].first = 10000000;
        out[ make_pair(inpQ[i].first, inpQ[i].second.first) ].second = 10000000;
    }
        
    sort( inpQ, inpQ + k );

    vector <int> sP;
    sP.push_back( inpQ[0].first );
    for(int i = 1; i < k; i++)
        if( inpQ[i].first != sP[ sP.size()-1 ] )
            sP.push_back( inpQ[i].first );
    sP.push_back( -1 );

    int pointer = 0;
    for(int i = 0; i < sP.size() - 1; i++)
    {
        vector < pair<int, int> > q; 
        q.push_back( make_pair( sP[i], 0 ) );

        for(int j = 0; j < q.size(); j++)
        {
            int p = q[j].first;
            int pp = q[j].second;

            for(int l = 0; l < nei[p].size(); l++)
            {
                int s = nei[p][l]; 
                if( !vis[s][ (pp+1)%2 ] )
                {
                    vis[s][ (pp+1)%2 ] = true;
                    path[s][ (pp+1)%2 ] = pp+1;
                    q.push_back( make_pair(s, pp+1) );
                }
            }
                
        }

        while( inpQ[pointer].first == sP[i] )
        {
            int inpQb = inpQ[pointer].second.first, inpQc = inpQ[pointer].second.second;
            if( vis[inpQb][inpQc%2] )
                if( inpQc%2 )
                    out[ make_pair( sP[i], inpQb ) ].second = path[inpQb][inpQc%2];
                else
                    out[ make_pair( sP[i], inpQb ) ].first = path[inpQb][inpQc%2];
            pointer++;
        }

        for(int j = 1; j <= _maxN; j++)
        {
            vis[j][0] = false;
            vis[j][1] = false;
        }
    }

    for(int i = 0; i < k; i++)
    {
        a = inp[i][0], b = inp[i][1], c = inp[i][2];
        if( c%2 == 0 )
        {
            if( out[ make_pair(a, b) ].first <= c ) 
                cout << "TAK" << endl;
            else
                cout << "NIE" << endl;
        }
        else
        {
            if( out[ make_pair(a, b) ].second <= c )
                cout << "TAK" << endl;
            else
                cout << "NIE" << endl;
        }  
    }
}
