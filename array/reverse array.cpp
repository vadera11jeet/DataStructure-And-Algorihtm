#include<bits/stdc++.h>
using namespace std;

void reverse_(int arr[], int start, int end_)
{
    while(start < end_)
    {
        int temp = arr[start];
        arr[start] = arr[end_];
        arr[end_] = temp;

        start ++;
        end_ --;

    }
}

int main()
{
    int arr [] = {1, 2, 3, 4, 5, 6};

    int n = 6;

    reverse_(arr, 0, n-1);

    for(int x : arr)
        cout<<x<< " " ;

    return 0;
}
