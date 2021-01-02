#include<iostream>
#include<cmath>
using namespace std;
// in this problem we have to create grammar
// if 0 is given than it next row is 0 1
// if 1 is given than it next row is 10
// 0
// 0 1
// 0 1 1 0
// 0 1 1 0 1 0 0 1
// in this argument we provide 4, 3 means 4 th row and 3rd col so ans is 1
// in this question base condition is given in question for n = 1 and k = 1 ans is 0
int grammar(int n, int k)
{
    if(n == 1 && k == 1)
        return 0;
    int mid = pow(2, n-2);
    if(k <= mid)
        return grammar(n-1, k);

    else
        return !grammar(n-1, k - mid);
}

int main()
{
    cout<<grammar(4, 3)<< " ";
    return 0;
}
