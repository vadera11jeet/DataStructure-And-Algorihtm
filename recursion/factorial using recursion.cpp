#include<iostream>
using namespace std;

int factorial(int a)
{
    int fact;
    if(a == 1)
        return 1;
    fact = a * factorial(a-1);
    return fact;
}

int main()
{
    cout<< factorial(5);

    return 0;
}
