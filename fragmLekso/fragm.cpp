#include<iostream>
using namespace std;

typedef long long ll;

const int _maxN = 500000; 
const ll _sP = 31;
const ll _lP = 1000000003;

ll hashT[_maxN][2];

int hashF( string data, int p )
{
    int n = data.size();

    hashT[0][p] = int( data[0] );
    for(int i = 1; i < n; i++)
        hashT[i][p] = (hashT[i-1][p] * _sP + int(data[i])) % _lP;
}

int main()
{
    string inp1, inp2;
    cin >> inp1 >> inp2;
    hashF( inp1, 0 );
    hashF( inp2, 1 );
    
    int beg = 0, end = inp1.size(), mid, out = 0;
    while( beg <= end )
    {
        mid = (beg + end)/2;
        if( hashT[mid][0] == hashT[mid][1] )
        {
            beg = mid + 1;
            out = hashT[mid + 1][0] > hashT[mid + 1][1];
        }
        else
            end = mid - 1;
    }
    cout << out;
}