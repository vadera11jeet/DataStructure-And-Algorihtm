#include<iostream>
using namespace std;

void binToDec(int n)
{
    if(n == 0)
        return ;
    binToDec(n/2);
    cout<< n%2;
}

int main()
{
    binToDec(66);
    return 0;
}
