#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef long long ll;

const int _maxN = 100001;
const int _sP = 31;
const int _lP = 1000000003;

ll hashT[_maxN][5];
ll powT[_maxN];

void hashF(string data, int index)
{
    int n = data.size();
    hashT[n-1][index] = int( data[n-1] );
    for(int i = n - 2; i >= 0; i--)
        hashT[i][index] = (hashT[i + 1][index] * _sP + int( data[i] ) ) % _lP;
}
int findR(int a, int b, int index)
{
    ll out = hashT[a][index];
    ll rmv = ( hashT[b + 1][index] * powT[b-a + 1] ) %_lP;
    out -= rmv;
    if(out < 0) return out + _lP;
    return out;
}

map< int, int > isHash;
string inp[5];
bool isOk(int mid)
{
    if( mid == 0 ) return true;
    for(int i = 0; i < 5; i++)
    {
        int temp = inp[i].size() - mid + 1;
        for(int j = 0; j < temp; j++)
        {
            ll nowHash = findR(j, j + mid - 1, i);
            if( isHash[nowHash] == i )
                isHash[nowHash]++;
            if( isHash[nowHash] == 5 )
                return true;
        }
    }
    isHash.clear();
    return false;     
}

int main()
{
    powT[0] = 1;
    for(int i = 1; i < _maxN; i++)
        powT[i] = (powT[i - 1] * _sP) % _lP;

    for(int i = 0; i < 5; i ++)
        cin >> inp[i];
    for(int i = 0; i < 5; i++) 
        hashF(inp[i], i);

    int start = 0, end = inp[0].size(), mid, out;
    while( start <= end )
    {
        mid = (start + end) / 2;

        if( isOk(mid) )
        {
            start = mid + 1;
            out = mid;
        }
        else
            end = mid - 1;
    }
    cout << out;
}