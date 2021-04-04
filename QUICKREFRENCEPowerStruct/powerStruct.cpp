#include<iostream>
using namespace std;

struct powerStruct
{
    int vLimit = 1000000000;
    long long base[50];

    void setBase( int val )
    {
        base[0] = val;
        for(int i = 1; i < 50; i++)
            base[i] = ( base[i - 1] * base[i - 1] ) % vLimit;
    }
    
    bool bin[50];
    int toBin(int val, int it = 0)
    {
        if( val == 0 ) return it;
        bin[it] = val % 2;
        return toBin( val/2, it + 1 );
    }

    long long request( int exp )
    {
        int n = toBin(exp);
        long long out = 1;
        for(int i = 0; i < n; i++)
            if( bin[i] )
                out *= base[i];
        return out;
    }
};


int main()
{
    powerStruct pow;
    pow.setBase(31);
    cout << pow.request(3);
}
