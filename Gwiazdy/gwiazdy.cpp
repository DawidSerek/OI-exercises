#include<iostream>
using namespace std;

const int _maxN = 15;

int cost[_maxN][2];
bool side[_maxN];
int nxt[_maxN];

int limit[2];
int s;

int main()
{
    int n;
    cin >> n >> s;
    n--;
    limit[0] = 1;
    limit[1] = n + 1;

    for(int i = 0; i < n; i++)
    {
        cin >> cost[i][0] >> cost[i][1];
        side[i] = cost[i][0] > cost[i][1];
    }
    
    int tNxt = 0;
    bool prvV = side[n-1];
    for(int i = n - 1; i >= 0; i--)
    {
        if( prvV != side[i] )
        {
            prvV = !prvV;
            nxt[i+1] = tNxt;
            tNxt = 1;
        }
        else
            tNxt++;
    }
    nxt[0] = tNxt;


}