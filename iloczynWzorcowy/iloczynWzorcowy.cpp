#include<iostream>
using namespace std;

const int _maxN = 1000000;

int KMP[_maxN];


int main()
{
    string inp;
    cin >> inp;
    inp = "$" + inp;

    int n = inp.size(), p = 0;
    for(int i = 2; i < n; i++) 
    {
        while( p > 0 && ( inp[p + 1] != inp[i] || p >= (i+1)/2 ) )
            p = KMP[p];
        if( inp[p + 1] == inp[i] ) 
            p++;
        KMP[i] = p;
    }
    for(int i = 0; i < n; i++) 
        cout << KMP[i] << " "; 

}