#include<bits/stdc++.h>
using namespace std;

int kadensAlgo(int arr[], int n)
{
    int curr_sum = arr[0];
    int overAll_sum = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(curr_sum >= 0)
            curr_sum += arr[i];
        else
            curr_sum = arr[i];

        if(curr_sum > overAll_sum)
            overAll_sum = curr_sum;
    }

    return overAll_sum;

}

int main()
{
    int arr[] = {1,2,3,-2,5};

    cout<<kadensAlgo(arr,5);

    return 0;
}
