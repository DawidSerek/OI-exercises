#include <iostream>
#include<vector>
using namespace std;

const int _maxN = 1000000;

vector <int> sas[_maxN];
bool vis[_maxN];

bool isArtP[_maxN];

int DFSdt[_maxN];
int DFSd = 0;

int DFSar(int v, int p = -1)
{
    DFSd++;
    DFSdt[v] = DFSd;
    vis[v] = true;

    int low = DFSd;
    int nCnt = 0;
    for(int i = 0; i < sas[v].size(); i++) //check for sons that are connected to ancestors
    {
        int n = sas[v][i];
        if( n == p || vis[n] ) continue;

        nCnt++;

        int temp = DFSar( n , v );
        if( temp >= DFSdt[v] ) isArtP[v] = true;
        low = min( low, temp );
    }

    if( p == -1 && nCnt < 2 ) isArtP[v] = false; //correct answear when parent actually has less than 2 sons

    for(int i = 0; i < sas[v].size(); i++) //correct low value
    {
        int n = sas[v][i];
        if( n != p )
            low = min( low, DFSdt[n] );
    }

    return low; //return LOW as the son
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
        if( !vis[i] )
            DFSar(i);

    cout << endl;
    for(int i = 0; i < n; i++)
        if( isArtP[i] )
            cout << i << " ";
}
