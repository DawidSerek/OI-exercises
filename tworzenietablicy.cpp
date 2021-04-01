#include <iostream>
using namespace std;

int t[1000000];

int main()
{
    int n, k;
    cin >> n >> k;

    int temp = (n/2) * - 1;
    for(int i = 0; i < n; i++)
        t[i] = temp + i;

    if( k < 0 )
        t[0] += k;
    else
        t[n - 1] += k;

    for(int i = 0; i < n; i++)
        cout << t[i] << " ";

}
