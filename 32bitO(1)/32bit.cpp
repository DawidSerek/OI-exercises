#include<iostream>
using namespace std;

#define bitS 65536

int q[bitS];

int cntBit(int v)
{
    int out = 0;
    while( v > 0 ){
        out += v%2;
        v /= 2;
    }
    return out;
}

int main()
{
    int z;
    cin >> z;

    for(int i = 0; i < bitS; i++)
        q[i] = cntBit(i);

    int inp;
    for(int i = 0; i < z; i++)
    {
        cin >> inp;
        int a = inp % bitS;
        int b = inp / bitS;
        cout << q[a] + q[b] << endl;
    }

}