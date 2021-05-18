#include<iostream>
#include<string>

using namespace std;

const int _maxN = 10;

bool inp[_maxN][_maxN];
bool temp[_maxN][_maxN];

int n = 10;
void sBool(int x, int y) //switches chosen var from table
{
    temp[x][y] = temp[x][y] != 1;
}

void pCross(int x, int y) //places ,,reversion cross"
{
    sBool(x,y);
    if( x+1 < n ) sBool( x+1, y );
    if( y+1 < n ) sBool( x, y+1 );
    if( x-1 >= 0 ) sBool( x-1, y );
    if( y-1 >= 0 ) sBool( x, y-1 );
}

void reset()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            temp[i][j] = inp[i][j];
}

bool isClear()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(temp[i][j] == true) return false;
    return true;
}

int isOk()
{
    int out = 0;
    for(int y = 1; y < n; y++)
        for(int x = 0; x < n; x++)
            if( temp[x][y-1] == true ) 
            {
                pCross(x,y);
                out++;
            }
    return out;
}

int main()
{
    cin >> n;

    string line;
    for(int i = 0; i < n; i++)
    {
        cin >> line;
        for(int j = 0; j < n; j++) 
            if( line[j] == '1' ) inp[j][i] = true;
            else inp[j][i] = false;
    }

    int out = -1;
    for(int i = 0; i < 1 << n; i++)
    {
        reset();
        int tOut = 0;
        for(int j = 0; j < n; j++) 
            if( ( i & 1 << j ) > 0 ) 
            {
                pCross(j,0);
                tOut++;
            }
        tOut += isOk();
        if( isClear() ) out = tOut;
    }
    cout << out;

    return 0;
}