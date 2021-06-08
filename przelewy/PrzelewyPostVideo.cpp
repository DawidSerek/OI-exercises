#include<iostream>
#include<vector>
using namespace std;

const int _maxN = 1000000;

int val[_maxN + 1];
vector <int> nei[_maxN + 1];

int vis[_maxN + 1];
int sumInf[_maxN + 1];
int DFSsum(int t)
{
    vis[t] = true;
    sumInf[t] = val[t];
    for(int i = 0; i < nei[t].size(); i++)
    {
        int neighbour = nei[t][i];
        if( !vis[neighbour] )
            sumInf[t] += DFSsum(neighbour);
    }
    return sumInf[t];
}

int mvs[_maxN + 1];
void DFSmvs(int t, int p)
{
    vis[t] = true;
    mvs[t] = sumInf[t] + mvs[p];

    for(int i = 0; i < nei[t].size(); i++)
    {
        int neighbour = nei[t][i];
        if( !vis[neighbour] ) DFSmvs( neighbour, t );
    }
}

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> val[i];
    
    int temp, sum = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> temp;
        val[i] -= temp;
        sum += val[i];
    }
    if(sum != 0)
    {
        cout << "NIE";
        return 0;
    }
    cout << "TAK" << endl;

    int a, b;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }

    DFSsum(1);
    for(int i = 0; i <= n; i++)
        vis[i] = 0;
    DFSmvs(1, 1);

    int out = 0, minMvs = 0;
    for(int i = 1 ; i <= n; i++)
    {
        out += mvs[i];
        minMvs = min(mvs[i], minMvs);
    }
    if(minMvs < 0) out += abs(minMvs) * n;
    cout << out;
    return 0;
}