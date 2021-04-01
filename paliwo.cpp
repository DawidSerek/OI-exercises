#include <iostream>
#include<vector>
using namespace std;

const int _maxN = 1000000;

vector <int> sas[_maxN + 1];
bool vis[_maxN];

pair<int, int> BFS(int r = 1)
{
    vector < pair<int, int> > q;
    q.push_back( make_pair( r, 0 ) );
    for(int i = 0; i < q.size(); i++)
    {
        int p = q[i].first;
        for(int j = 0; j < sas[p].size(); j++)
        {
            int n = sas[p][j];
            if( !vis[ n ] )
            {
                vis[n] = true;
                q.push_back( make_pair( n, q[i].second + 1 ) );
            }
        }
    }
    return q.back();
}

int main()
{
    int n, m;
    cin >> n >> m;

    int a, b;
    for( int i = 0; i < n - 1; i ++ )
    {
        cin >> a >> b;
        sas[a].push_back(b);
        sas[b].push_back(a);
    }

    pair<int, int> temp = BFS();
    for(int i = 0; i < _maxN; i++)
        vis[i] = false;

    int minEd = BFS(temp.first).second;

    int out1, out2;
    out1 = min( minEd, m );
    m -= out1;
    out2 = min( m/2, n - 1 - out1 );
    cout << 1 + out1 + out2;
}
