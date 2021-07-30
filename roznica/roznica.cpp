#include<iostream>
using namespace std;

const int _alphS = 26;

int cnt[_alphS];
bool isOk[_alphS];

int main()
{
    int n;
    string inp;
    cin >> n >> inp;

    int bfrIn = inp[0] - 'a', nowIn, out = 0;
    for( int i = 0; i < n; i++ )
    {
        nowIn = inp[i] - 'a';
        cnt[nowIn]++;
        if( nowIn != bfrIn ) isOk[ bfrIn ] = true;
        for( int j = 0; j < _alphS; j++ )
        {
            if( isOk[j] ) out = max( out, cnt[j] );
        }
        bfrIn = nowIn;
    }
    cout << out;
    return 0;
}