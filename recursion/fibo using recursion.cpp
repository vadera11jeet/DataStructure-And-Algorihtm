#include<iostream>
using namespace std;

int fibo(int n)
{
    if(n <= 1)
        return n;
    int a = fibo(n-1) + fibo(n-2) ;
    return a ;
}

int main()
{
    cout<<fibo(7);
    return 0;
}
