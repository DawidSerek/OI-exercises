#include <iostream>
#include <vector>
#include<map>
using namespace std;

const int _maxN = 1000000;

vector <int> sas[_maxN];

int DFSd = 0;
int DFSdt[_maxN];
bool vis[_maxN];
int lowt[_maxN];
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

    lowt[v] = low;
    return low;
}

bool ans1[_maxN];
pair<int, int> inp[_maxN];
int main()
{
    int n, m;
    cin >> n >> m;

    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        inp[i] = make_pair( min(a, b), max(a, b) );
        sas[a].push_back(b);
        sas[b].push_back(a);
    }

    for(int i = 0; i < _maxN; i++)
        if(!vis[i])
           DFSb(i);


    cout << endl;
    for(int i = 0; i <= n; i++)
        cout << "[" << i << "]";
    cout << endl;
    for(int i = 0; i <= n; i++)
        cout << " " << lowt[i] << " ";
    cout << endl;
    int out = 0;
    for(int i = 1; i <= n; i++)
        if( !ans1[ lowt[i] ] )
        {
            ans1[ lowt[i] ] = true;
            out++;
        }
    cout << out;
}
