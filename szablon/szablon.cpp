#include<iostream>
#include<algorithm>

using namespace std;
const int _maxN = 100;

int KMP[_maxN];

int main()
{
    string inp;
    cin >> inp;
    inp = '#' + inp;

    int p = 0;
    for(int i = 2; i < inp.size(); i++)
    {
        while( p > 0 && inp[p + 1] != inp[i]  )
            p = KMP[p];
        if( inp[p + 1] == inp[i] )
            p++;
        KMP[i] = p;
    }

    for(int i = 1 ; i < inp.size(); i++)
        cout << KMP[i] /*<< inp[i]/**/ << " ";

    return 0;
}
