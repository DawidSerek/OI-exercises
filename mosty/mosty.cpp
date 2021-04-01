#include <iostream>
#include <vector>
using namespace std;

const int _maxN = 1000000;

vector <int> sas[_maxN];
vector < pair<int, int> > ans;

int DFSd = 0;
int DFSdt[_maxN];
bool vis[_maxN];
int DFSb(int v, int p = -1)
{
    DFSd++;
    DFSdt[v] = DFSd;
    vis[v] = true;

    int low = DFSdt[v];
    int pCnt = 0;
    for(int i = 0; i < sas[v].size(); i++)
    {
        int n = sas[v][i];
        if( n == p )
        {
            pCnt++;
            if(pCnt < 2) continue;
        }

        if( !vis[n] ) 
            low = min( low, DFSb(n , v) ); //take low from son
        else
            low = min( low, DFSdt[n] ); // take low from back edge
    }

    if( low == DFSdt[v] && p != -1 ) ans.push_back( make_pair( v, p ) ); //add bridge if it does not relate to root edge
    return low;
}


int main()
{
    int n, m;
    cin >> n >> m;

    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        sas[a].push_back(b);
        sas[b].push_back(a);
    }

    for(int i = 0; i < _maxN; i++)
        if(!vis[i])
           DFSb(i);

    cout << endl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}
