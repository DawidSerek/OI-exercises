#include <bits/stdc++.h>
using namespace std;

const int _maxN = 5000;
const int _maxK = 1000000;
int n, m, k;

struct inpV
{
    int a, b, d, valIt;
    bool ans;
};
inpV inp[_maxN + 1];
bool compA( inpV inpV1, inpV inpV2 )
{
    return inpV1.a < inpV2.a;
}
bool compValIt( inpV inpV1, inpV inpV2 )
{
    return inpV1.valIt < inpV2.valIt;
}

vector <int> nei[_maxN + 1];
bool vis[_maxN + 1][2];
int path[_maxN + 1][2];
void BFS(int s, int fIt, int lIt)
{
    vector < pair<int, int> > q;
    q.push_back( make_pair(s, 0) );
    for(int i = 0; i < q.size(); i++)
    {
        int par = q[i].first;
        int parP = q[i].second;
        for(int j = 0; j < nei[par].size(); j++)
        {
            int son = nei[par][j];
            if( !vis[son][ (parP+1)%2 ] )
            {
                q.push_back( make_pair(son, parP+1) );
                vis[son][(parP+1)%2] = true;
                path[son][(parP+1)%2] = parP + 1;
            }
        }  
    }

    for(int i = fIt; i <= lIt; i++)
        if( inp[i].d % 2 == 0 )
            inp[i].ans = inp[i].d >= path[ inp[i].b ][0];
        else
            inp[i].ans = inp[i].d >= path[ inp[i].b ][1];
}

int main()
{
    cin >> n >> m >> k;

    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }
    for(int i = 0; i < k; i++)
    {
        cin >> inp[i].a >> inp[i].b >> inp[i].d;
        inp[i].valIt = i;
    }

    sort( inp, inp + k, compA );

    int temp = inp[0].a;
    int fIt = 0;
    inp[k].a = -1;
    for(int i = 0; i < k; i++)
    {
        if( temp != inp[i + 1].a )
        {
            for(int j = 0; j < _maxN + 1; j++)
            {
                vis[j][0] = false;
                vis[j][1] = false;
                path[j][0] = 1000000001;
                path[j][1] = 1000000001;
            }

            BFS( temp, fIt, i );
            temp = inp[i + 1].a;
            fIt = i + 1;
        }
    }

    sort( inp, inp + k, compValIt );

    for(int i = 0; i < k; i++)
        if( inp[i].ans )
            cout << "TAK" << endl;
        else
            cout << "NIE" << endl;
}