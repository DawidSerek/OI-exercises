#include <iostream>
using namespace std;

const int _maxN = 1000003;
const int bPrime = 37;

int has[_maxN];

int hasF(string tS)
{
    int hasV = 0, powP = bPrime;
    for(int i = 0; i < tS.size(); i++)
    {
        hasV += int(tS[i]) * powP;
        hasV %= _maxN;
        powP *= bPrime;
    }
    return hasV;
}


int main()
{
    string s1 = "Ala ma kota";
    string s2 = "Ala ma kota";

    if( hasF(s1) == hasF(s2) )
        cout << "TAK";
    else
        cout << "NIE";
}
