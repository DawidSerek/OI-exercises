#include<iostream>
using namespace std;

const int _maxN = 5000;

int LCS[_maxN][_maxN];

string LCSf(int i, int j, string a, string b)
{
    string aS = "";
    aS.push_back( a[i] );
    if( a[i] == b[j] && LCS[i][j] == 1 )
        return aS;
    if( a[i] == b[j] )
        return aS + LCSf(i-1, j-1, a, b);

    if( LCS[i-1][j] > LCS[i][j-1] )
        return LCSf(i-1, j, a, b);
    return LCSf(i, j - 1, a, b);

}

string LCSfix(int i, int j, string a, string b)
{
    string temp = LCSf(i,j,a,b);
    string out = "";

    for(int i = temp.size() - 1; i >= 1; i--)
        out.push_back( temp[i] );
    return out;
}

int main()
{
    string a, b;
    cin >> a >> b;
    a = '#' + a;
    b = '#' + b;

    for(int i = 1; i < a.size(); i++)
        for(int j = 1; j < b.size(); j++)
            if( a[i] == b[j] )
                LCS[i][j] = LCS[i-1][j-1] + 1;
            else
                LCS[i][j] = max( LCS[i-1][j], LCS[i][j-1] );


    for(int i = 0; i < b.size(); i++)
        {
            for(int j = 0; j < a.size(); j++)
                cout << LCS[j][i] << " ";
            cout << endl;
        }

    cout << LCSfix( a.size(), b.size(), a, b );
}
