#include<iostream>
using namespace std;

int KMP[1000000];
int cnt[1000000];

int main()
{
    string s;
    cin >> s;
    s = '#' + s;

    int p = 0;
    for(int i = 2; i < s.size(); i++)
    {
        while( p > 0 && s[ p + 1 ] != s[i] )
            p = KMP[p];
        if( s[p + 1] == s[i] )
            p++;
        KMP[i] = p;
    }

    for(int i = 2; i < s.size() - 1; i++)
        cnt[ KMP[i] ]++;

    while( p > 0 && cnt[p] == 0 )
        p = KMP[p];

    cout << p;
}
