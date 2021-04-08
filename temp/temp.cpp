#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string temp = "";
    for (int i = 1; i < 500000; i++)
        temp += to_string(i) + " ";
    ofstream myfile;
    myfile.open("example.txt");
    myfile.open ("example123.txt");
    myfile << temp;
    myfile.close();
}