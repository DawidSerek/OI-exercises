#include<iostream>
using namespace std;

const int _maxN = 50000;
int t[_maxN];

int main()
{
    int n, a;
    cin >> n >> a;

    for(int i = 0; i <= n; i++)
        cin >> t[i];

    int temp = t[0];
    for(int i = 0; i <= n; i++)
    {
        cout << temp << " ";
        temp *= a;
        temp += t[i + 1];
    }
}