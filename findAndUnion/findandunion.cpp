#include <iostream>
#include<vector>
using namespace std;

const int _maxN = 5000000;

int fu[_maxN];

int f(int a)
{
    vector <int> q;
    while( a != fu[a] )
    {
        q.push_back(a);
        a = fu[a];
    }
    for(int i = 0; i < q.size(); i++)
        fu[ q[i] ] = a;
    
    return a;
}

void u( int a, int b )
{
    fu[ f(a) ] = f(b);
}


int main()
{
    int n = 500000;

    for(int i = 1; i < n; i++)
        fu[i] = i;
    
    for(int i = 1; i < n - 1; i++)
        u(i, i + 1);

    for(int i = 1; i < 5; i++)
        cout << f(i) << " ";

    return 0;
}
