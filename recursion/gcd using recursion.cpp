#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    while(a!=b)
    {
        if(a>b)
            return gcd(a-b, b);
        else
            return gcd(a, b-a);
    }
    return a;
}

int main()
{
    cout<<gcd(50,10);
    return 0;
}
