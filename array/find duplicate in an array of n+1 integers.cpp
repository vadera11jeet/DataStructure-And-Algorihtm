#include<bits/stdc++.h>
using namespace std;
// this code is only for n+1 int starts from 1

int main()
{
    int arr[] = { 0, 4, 3, 2, 7, 8, 2, 3, 1 };
    int n = 9;

    for(int i = 0; i < n; i++)
    {
        arr[arr[i] % n] = arr[arr[i]%n] + n;
    }

    for(int i = 0; i < n; i++)
        if(arr[i]/n > 1) cout<<i<<endl;

    return 0;
}
