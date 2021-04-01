#include <iostream>
#include<stdio.h>
using namespace std;

const int _maxN = 5000000;

int fu[_maxN];
int f(int inp, bool temp= false)
{
    if(temp) cout << inp << " ";
    if( fu[inp] == inp )
        return inp;

    fu[inp] = f( fu[inp], temp );
    return fu[inp];
}

int u(int a, int b)
{
    //printf( "%d %d\n", f(a), f(b) );
    fu[ f(a) ] = f(b);
}

int main()
{
    int n = 200000;

    for(int i = 1; i < n; i++)
        fu[i] = i;

    for(int i = 1; i < n - 2; i++)
        u(i, i+1);

    f(1, true);

    //for(int i = 1; i < n; i++)
        //cout << f(i) << " ";

    cout << "done";
}
