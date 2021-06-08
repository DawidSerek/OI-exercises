#include<iostream>
#include<vector>
using namespace std;

const int bitS = 65536;

int cnt[bitS];
vector<int>cntPre[bitS];

bool isRep(int n)
{
    for(int i = 0; i < bitS; i++)
    {
        for(int j = 0; j < cntPre[i].size(); j++)
        {
            cnt[ cntPre[i][j] ]++;
            if( cnt[ cntPre[i][j] ] > 1 ) return true;
        }
        for(int j = 0; j < cntPre[i].size(); j++)
            cnt[ cntPre[i][j] ]--;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    int a, pre;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        pre = a / bitS;
        cntPre[pre].push_back(a % bitS);
    }

    if(isRep(n)) cout << "TAK";
    else cout << "NIE";
}