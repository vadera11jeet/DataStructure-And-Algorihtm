#include<bits/stdc++.h>
using namespace std;


int partition_(int arr[], int pivot, int lo, int hi)
{
    int i = lo, j = lo;

    while(i < hi)
    {
        if(arr[i] <= pivot)
        {
            swap(arr[i], arr[j]);
            j++;
        }
        i++;
    }
    swap(arr[j], arr[hi]);
    return j ;

}

int quickSelect(int arr[], int lo, int hi, int k)
{
    int pivot = arr[hi];
    int pi = partition_(arr, pivot, lo , hi);

    if(k > pi)
        return quickSelect(arr, pi + 1, hi, k);
    else if(k < pi)
        return  quickSelect(arr, lo, pi - 1, k);
    else
        return pivot;

}


int main()
{
    int  arr[] = {7, 10, 4, 3, 20, 15};
//    3 4 7 10 15 20

    cout<<quickSelect(arr, 0, 5, 2);

    return 0;
}
