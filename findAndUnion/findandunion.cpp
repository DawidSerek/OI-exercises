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
    int n = 600000, z;
    cin >> z;

    for(int i = 1; i < n; i++)
        fu[i] = i;
    
    for(int i = 0; i < z; i++)
    {
        char choose;
        cin >> choose;

        int a, b;
        if( choose == 'F' )
        {
            cin >> a;
            cout << f(a) << " ";
        }
        else
        {
            cin >> a >> b;
            u(a, b);
        }
    }
    return 0;
}
