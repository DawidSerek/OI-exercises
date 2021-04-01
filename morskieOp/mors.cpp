#include <iostream>
#include<vector>
#include<map>
using namespace std;

const int _maxN = 6000;

namespace maps
{
    map < pair<int, int>, bool > vis;
    map < pair<int, int>, int > inp;
    map < pair<int, int>, pair<int, int> > out;
}

bool vis[_maxN][2];
int clr()
{
    for(int i = 0; i < _maxN; i++)
    {
        vis[i][0] = false;
        vis[i][1] = false;
    }
}

vector <int> sas[_maxN + 1];
vector < pair<int, int> > q;
int BFS( int r = 1 )
{
    maps::out[ make_pair(r, r) ].first = 0;

    q.push_back( make_pair(r, 0) );
    vis[r][0] = true;
    for(int i = 0; i < q.size(); i++)
    {
        int p = q[i].first;
        int dis = q[i].second + 1;

        for(int j = 0; j < sas[p].size(); j++)
        {
            int n = sas[p][j];
            if( !vis[n][dis % 2] )
            {
                vis[n][dis % 2] = true;
                q.push_back( make_pair(n, dis) );

                pair<int, int> tPair = make_pair( min(r, n), max(r, n) );
                if( maps::vis[tPair] )
                    if( dis % 2 == 0 )
                        maps::out[ tPair ].first = dis;
                    else
                        maps::out[ tPair ].second = dis;
            }
        }
    }
}

pair <int, int> inp[_maxN];
int main()
{
    int n, m, z;
    cin >> n >> m >> z;

    int a, b, c;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        sas[a].push_back(b);
        sas[b].push_back(a);
    }

    for(int i = 0; i < z; i++)
    {
        cin >> a >> b >> c;
        inp[i] = make_pair(a, b);
        pair<int, int> tPair = make_pair( min(a, b), max(a, b) );
        maps::inp[ tPair ] = c;
        maps::vis[ tPair ] = true;
        maps::out[ tPair ] = make_pair(-1, -1);
    }

    for(int i = 0; i < n; i++)
        BFS(i + 1);

    /*
    for(int i = 0; i < q.size(); i++)
        cout << q[i].first << " ";
    cout << endl;
    for(int i = 0; i < q.size(); i++)
        cout << q[i].second << " ";
    cout << endl;
    for(int i = 0; i < z; i++)
    {
        pair<int, int> tPair = make_pair( min(inp[i].first, inp[i].second), max(inp[i].first, inp[i].second) );
        cout << tPair.first << " " << tPair.second << "!" << maps::out[tPair].first << "!" << maps::out[tPair].second << endl;
    }
    /**/
    for(int i = 0; i < z; i++)
    {
        pair<int, int> tPair = make_pair( min(inp[i].first, inp[i].second), max(inp[i].first, inp[i].second) );
        int minEv = maps::out[tPair].first;
        int minOdd = maps::out[tPair].second;
        int querry = maps::inp[ tPair ];

        if( querry % 2 == 0 )
            if( minEv <= querry )
                cout << "TAK" << endl;
            else
                cout << "NIE" << endl;
        else
            if( minOdd <= querry )
                cout << "TAK" << endl;
            else
                cout << "NIE" << endl;
    }
}