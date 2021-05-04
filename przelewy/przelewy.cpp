#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

const int _maxN = 100;

ll diff[_maxN + 1];
vector <int> nei[_maxN + 1];
bool vis[_maxN + 1];

ll out = 0;
ll DFS(int p, int pp)
{
    vis[p] = true;
    ll dfsV = 0, maxCst = 0;
    for(int i = 0; i < nei[p].size(); i++)
    {
        int s = nei[p][i];
        if( !vis[s] ) maxCst = max( DFS(s, p) );
        out += maxCst;
    }
    diff[pp] += diff[p];
    return diff[p];
}


int main()
{
    int n, temp, sumPref = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> diff[i];
    for(int i = 1; i <= n; i++)
    {
        cin >> temp;
        diff[i] = diff[i] - temp;
        sumPref += diff[i];
    }

    int a, b;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }

    if( sumPref == 0 )
    {
        cout << "TAK" << endl;
        DFS(1, 0);
        cout << out;
    }
    else
        cout << "NIE";

    return 0;
}