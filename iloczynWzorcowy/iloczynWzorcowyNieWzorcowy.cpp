#include<iostream>
using namespace std;

typedef long long ll;

struct hashS{
    ll hashT[10000];
    ll pow[10000];
    int n;
    const ll _sP = 31;
    const ll _lP = 1000000003;

    void ini(string inp)
    {
        n = inp.size();

        hashT[0] = ll(inp[0]);
        for(int i = 1; i < n; i++)
            hashT[i] = ( hashT[i-1] * _sP + ll( inp[i] ) ) % _lP;
        
        pow[0] = 1;
        for(int i = 1; i < n; i++)
            pow[i] = (pow[i-1] * _sP) % _lP;
    }

    int hashF( int a, int b )
    {
        ll out, rmv = 0;
        out = hashT[b];
        if( a > 0 ) rmv = (hashT[a-1] * pow[b-a+1]) % _lP;

        if( out - rmv < 0 )
            return out - rmv + _lP;
        return out - rmv;
    }

};

int main()
{
    string inp = "ababbabbabbabbabababbaba";
    //string inp = "aaaaaaaaaaaaaaaaaaaa";
    //string inp = "abcdabaefghibjklaabmabnobaaa";
    //
    string inp = "abbaabba";
    for(int i = 1; i < inp.size(); i++)
    {
        string k ="";
        for(int j = 0; j < i; j++)
            k.push_back(inp[j]);

        cout << inp << endl;

        hashS key, word;
        key.ini(k);
        word.ini(inp);
        ll kHash = key.hashF(0, k.size() - 1);

        for(int j = 0; j < k.size(); j++)
            cout << " ";
        int temp = 0;
        for(int j = k.size(); j < inp.size(); j++)
        {
            if( word.hashF( j, j + k.size()-1 ) == kHash )
            {
                cout << "1";
                temp++;
            }
            else
                cout << " ";
        }
        cout << endl;
        cout << k.size() << " " << temp << " " << k.size() * temp << endl << endl;
    }
}