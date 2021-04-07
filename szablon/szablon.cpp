#include<iostream>
#include<algorithm>

using namespace std;
const int _maxN = 100;

int KMP[_maxN + 1];
bool can[_maxN + 1];

bool isOk(string inp, int can)
{
    return false;
}

int main()
{
    string inp;
    cin >> inp;
    inp = '#' + inp;
    int n = inp.size();

    int p = 0;
    for(int i = 2; i < inp.size(); i++)
    {
        while( p > 0 && inp[p + 1] != inp[i]  )
            p = KMP[p];
        if( inp[p + 1] == inp[i] )
            p++;
        KMP[i] = p;
    }

    can[n] = true;
    while( KMP[p] != 0 )
    {
        p = KMP[p];
        can[p] = true;
    }

    for(int i = 1; i <= n; i++)
    {
        if( can[i] )
            if( isOk(inp, i) )
            {
                cout << i;
                break;
            }
            else
                for( int j = i + 1; j <= 2 * i || j <= n; j++ )
                    can[j] = false;
    }
        

    // for(int i = 1 ; i < inp.size(); i++)
    //     cout << KMP[i] /*<< inp[i]/**/ << " ";

    return 0;
}

