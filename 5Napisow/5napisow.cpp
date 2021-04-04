#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

struct hashStruct
{
    const int _maxN = 5000;
    const int _sP = 31;
    const int _lP = 1000000003;
    ll hashT[5000];
    ll pow[5000];

    void ini(string inp)
    {
        int n = inp.size();

        pow[0] = 1;
        for(int i = 1; i < n; i++)
            pow[i] = (pow[i-1] * _sP) % _lP;

        hashT[n-1] = int( inp[n-1] );
        for( int i = n - 2; i >= 0; i-- )
            hashT[i] = ( hashT[i + 1] * _sP + int(inp[i]) ) % _lP;
    }

    ll hRange(int a, int b)
    {
        ll out = hashT[a];
        ll rmv = (hashT[b+1] * pow[ b-a + 1 ]) % _lP;
        out -= rmv;

        if( out < 0 )
            return out + _lP;
        return out;
    }

};

int main()
{
    string inp[5];
    for(int i = 0; i < 5; i++)
        cin >> inp[i];

    hashStruct hashStr[5];
    for(int i = 0; i < 5; i++)
        hashStr[i].ini(inp[i]);
    
    int n = inp[0].size(), minN = inp[0].size();
    for(int i = 1; i < 5; i++)
        minN = min( minN, int(inp[i].size()) );

    int out = 0;
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
        {
            ll exHash = hashStr[0].hRange(i, j);
            int range = j-i;
            bool isOk = true;
            for(int k = 1; k < 5; k++)
            {
                bool isItOk = false;
                for(int l = 0; l + range < inp[k].size(); l++)
                    if( hashStr[k].hRange(l, l + range) == exHash )
                        isItOk = true;
                if( !isItOk )
                    isOk = false;
            }
            if(isOk)
                out = max(out, range + 1);
        }
        
    cout << out;
    return 0;
}