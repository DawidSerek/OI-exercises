#include<iostream>
#include<vector>
#include<map>
using namespace std;

const int _maxN = 16;
const int _logN = 4 + 2;

vector <int> KMR[_logN];
map < pair<int, int>, int> KMRR;

#define SHIFT ( 1 << (i-1) )

int main()
{
    string inp;
    cin >> inp;
    int n = inp.size();

    int maxV = -1;
    for(int i = 0; i < n; i++)
    {
        int charV = inp[i] - 'a';
        KMR[0].push_back( charV );
        maxV = max( maxV, charV );
    }
    
    for(int i = 1; i < _logN; i++)
        for(int j = 0; j + SHIFT < KMR[i-1].size(); j ++ )
        {
            pair<int, int> crrPair = make_pair( KMR[i-1][j], KMR[i-1][ j + SHIFT ] );
            if( KMRR[crrPair] == 0 )
            {
                maxV++;
                KMRR[crrPair] = maxV;
            }
            KMR[i].push_back( KMRR[crrPair] );
        }

    for(int i = 0; i < _logN; i++)
    {
        for(int j = 0; j < KMR[i].size(); j++)
            cout << KMR[i][j] << " ";
        cout << endl;
    }
        
}