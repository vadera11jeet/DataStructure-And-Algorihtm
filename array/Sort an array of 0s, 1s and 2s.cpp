#include<bits/stdc++.h>
using namespace std;


void sortArrayOf012(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int hi = n -1;

    while(mid <= hi)
    {
//       here if we find mid element as 0 then we swap this element with middle
        if(arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low ++;
        }
//        if we find middle element is 1 then we do nothig
        else if(arr[mid] == 1)
            mid++;
//       if we find 2 as element we swap this mid element and higher element
        else
        {
            swap(arr[mid], arr[hi]);
            hi--;
        }
    }

}

int main()
{
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = 12;

    sortArrayOf012(arr, n);

    for(int x : arr)
        cout<< x << "  ";

    cout<<endl;

    return 0;
}
