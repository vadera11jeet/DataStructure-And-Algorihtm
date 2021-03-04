#include<bits/stdc++.h>
using namespace std;

void movingNegativeNumber(int arr[], int n)
{
    int low = 0;
    int high = n - 1;

    while(low <= high)
    {
        if(arr[low] > 0)
        {
            swap(arr[low], arr[high]);
            high--;
        }
        else
            low++;
    }

}


int main()
{
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = 9;
    movingNegativeNumber(arr, n);

    for(int x : arr)
        cout<<x<< "  ";


    return 0;
}
