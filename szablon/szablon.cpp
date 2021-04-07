#include<iostream>
using namespace std;

const int _maxN = 500000;

int KMP[_maxN * 2 + 2];
bool kmpCan[_maxN + 1];
string inp;

void KMPf( string txt )
{
    int n = txt.size();
    int p = 0;
    for(int i = 2; i < n; i++)
    {
        while( p > 0 && txt[p + 1] != txt[i] )
            p = KMP[p];
        if( txt[p + 1] == txt[i] )
            p++;
        KMP[i] = p;
    }
}

bool isOk(int can)
{
    string candidate = "";
    for(int i = 0; i <= can; i++)
        candidate += inp[i];
    string outStr = candidate + inp;
    KMPf( outStr );

    int limit = can;
    for( int i = can + 2; i < outStr.size(); i++ )
    {
        limit--;
        if( KMP[i] == can )
            limit = can;
        if( limit == 0 )
            return false;
    }
    return true;
}

int main()
{
    cin >> inp;
    inp = "#" + inp;
    
    KMPf( inp );
    int p = inp.size() - 1;
    while( p != 0 )
    {
        kmpCan[p] = true;
        p = KMP[p];
    }
    
    for(int i = 1; i <= inp.size(); i++)
    {
        if( kmpCan[i] )
            if( isOk(i) )
            {
                cout << i;
                break;
            }
            else
                i = i * 2;
    }
    return 0;
}
