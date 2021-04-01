#include <iostream>
#include<vector>
using namespace std;

const int _maxN = 100001;

vector <int> nei[_maxN];

int low[_maxN];
bool vis[_maxN];
int cntr = 0;

int tar(int v, int minP)
{
    cntr++;
    vis[v] = true;
    low[v] = cntr;

    int tLow = cntr;
    for(int i = 0; i < nei[v].size(); i++)
    {
        int n = nei[v][i];
        if( !vis[n] )
            tLow = min( tLow, tar(n, minP) );
        else
            tLow = min( tLow, low[n] );
    }
    tLow = max( minP, tLow );

    low[v] = tLow;
    return tLow;
}

bool isVis[_maxN];
int main()
{
    int n, m;
    cin >> n >> m;

    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        nei[a].push_back(b);
    }

    for(int i = 1; i < _maxN; i++)
        if( !vis[i] )
            tar(i, i);

    int temp = n;
    for(int i = 1; i < _maxN; i++)
        if( !isVis[ low[i] ] )
            isVis[ low[i] ] = true;
        else
            temp--;
    cout << temp << endl;

    /*
    for(int i = 1; i <= n; i++)
        cout << low[i] << " ";
    /**/
}
