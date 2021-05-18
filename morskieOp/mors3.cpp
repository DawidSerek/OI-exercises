#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX_N 5000
#define MAX_K 1000000

struct inpV //structure dedicated to organising querries
{
    short a, b;
    int path, index;
    bool ans = false;
};

bool compA(inpV a, inpV b)
{
    return a.a < b.a;
}

bool compIndex(inpV a, inpV b)
{
    return a.index < b.index;
}


vector<short> nei[MAX_N + 1];
int BFSpath[MAX_N + 1][2]; //stores paths to every point from current one
bool vis[MAX_N + 1][2];
void BFS(short beg) //updates paths for current constant number
{
    for(int i = 0; i < MAX_N + 1; i++)
    {
        BFSpath[i][0] = 0;
        BFSpath[i][1] = 0;
        vis[i][0] = false;
        vis[i][1] = false;
    }

    vector< pair<short, int> > q;
    q.push_back( make_pair(beg, 0) );
    for(int i = 0; i < q.size(); i++)
    {
        short p = q[i].first;
        int sp = q[i].second + 1;
        for( int j = 0; j < nei[p].size(); j++ )
        {
            short s = nei[p][j];
            if( !vis[s][ sp % 2 ] )
            {
                vis[s][ sp%2 ] = true;
                q.push_back( make_pair(s, sp) );
                BFSpath[s][ sp % 2 ] = sp;
            }
        }
    }
    return;
}

inpV inp[MAX_K + 1]; //stores input values
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    short a, b;
    for(int i = 0; i < m; i++) //reading input reagarding graph
    {
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }
    for(int i = 0; i < k; i++) //reading input regarding querries
    {
        cin >> inp[i].a >> inp[i].b >> inp[i].path;
        inp[i].index = i;
    }

    sort( inp, inp + k, compA );

    vector <short> thisQ; //stores currently processed querries (with first number)
    int diff = inp[0].a;
    inp[k].a = -1;
    for(int i = 0; i <= k; i++) 
    {
        if( diff == inp[i].a ) //trace if there has been change made regarding first number
            thisQ.push_back( inp[i].b );
        else
        {
            BFS(diff);
            for(int j = i - 1; thisQ.size() > 0; j--) //finds solution for all querries with first number
            {   
                int minPath = BFSpath[ thisQ.back() ][ inp[j].path % 2 ];
                if( minPath != 0 ) 
                    inp[j].ans = minPath <= inp[j].path;
                thisQ.pop_back();
            }

            thisQ.push_back( inp[i].b );
            diff = inp[i].a;
        }
    }
    
    sort( inp, inp + k, compIndex );

    for(int i = 0; i < k; i++)
        if( inp[i].ans ) printf( "%s", "TAK\n" );
        else printf( "%s", "NIE\n" );
    
    return 0;
}