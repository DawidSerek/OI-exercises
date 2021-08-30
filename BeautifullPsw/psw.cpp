#include<iostream>
#include<vector>
#include<map>
using namespace std;

const int _alphS = 36;
const int _maxN = 16 + 1;

int cnt[_alphS];
int keys[_maxN];

map < vector<bool>, int > keyG;

int charInt( char a )
{
    int nmb = int(a);
    if( nmb >= 97 ) nmb -= 87;
    else nmb -= 48;
    return nmb;
}

void restartCnt()
{
    for(int i = 0; i < _alphS; i++) cnt[i] = 0;
}

void keyPrep( bool isPrePrep, string &S )
{
    vector <bool> temp;
    
    if( !isPrePrep )
    {
        for(int j = 0; j < _alphS; j++) temp.push_back( cnt[j] % 2 );
        keyG[temp] = 0;
    }

    for(int i = 0; i < S.size(); i++)
    {
        temp.clear();
        cnt[ charInt( S[i] ) ]++;
        for(int j = 0; j < _alphS; j++) temp.push_back( cnt[j] % 2 );

        if( isPrePrep ) keyG[ temp ] = _maxN;
        else
        {
            keyG[temp] = min( keyG[ temp ], i + 1 );
            keys[i] = keyG[temp];
        } 
    }
}

int solution(string &S)
{
    keyPrep( true, S );
    restartCnt();
    keyPrep( false, S );
    restartCnt();

    int out = 0;
    for(int i = 0; i < S.size(); i++)
        out = max( out, i - keys[i] + 1);
    return out;
}


int main()
{
    string inp;
    cin >> inp;
    cout << solution( inp );
}