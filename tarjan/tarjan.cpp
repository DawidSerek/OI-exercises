#include <iostream>
#include<vector>
using namespace std;

const int _maxN = 1000000;

vector <int> vN[_maxN];

bool vis[_maxN];
int DFSv[_maxN];
int Low[_maxN];
int ec[_maxN];
int it = 0;

int DFS( int v = 1, int p = -1 )
{
    vis[v] = true;
    ec[p] = v;

    it++;
    DFSv[v] = it;
    int minVal = it;

    int isR = false;
    for(int i = 0; i < vN[v].size(); i++ )
    {
        int n = vN[v][i]; //simplifying neighbour name
        if( n == p && !isR )//skip cases where neighbour is parent, unless we have double (or more) paths to it
        {
            isR = true;
            continue;
        }

        if( vis[n] )//that means that it's back edge
        {
            if( minVal > DFSv[n] )
                ec[v] = n;
            minVal = min( minVal, DFSv[n] );

        }
        else //that means son's edge
            minVal = min( minVal, DFS(n, v) );
    }

    Low[v] = minVal;
    return minVal;
}


bool temp[_maxN];
pair<int, int> inp[_maxN];

int main()
{
    int n, m, a, b;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;

        inp[i].first = a;
        inp[i].second = b;

        vN[a].push_back(b);
        vN[b].push_back(a);
    }

    for(int i = 1; i <= _maxN; i++) //find independent cycles
        if( !vis[i] && i <= n )
            DFS(i);

    for(int i = 1; i <= _maxN; i++)
        vis[i] = false;



    int cycC = 0;
    for(int i = 1; i < _maxN; i++)
        if( !temp[ Low[i] ] && Low[i] != 0 )
        {
            temp[ Low[i] ] = true;
            cycC++;
        }


    cout << cycC << endl;
    for(int i = 0; i < m; i++)
        if( inp[i].second == ec[inp[i].first] )
        {
            cout << "<";
            ec[inp[i].first] = -1;
        }
    else
        cout << ">";

}
