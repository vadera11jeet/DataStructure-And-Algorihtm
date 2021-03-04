#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 5, 9, 10, 15, 20}, arr1 = {2, 3, 8, 13};

    int i = arr.size()-1;
    int j = 0;

    while(i >= 0 && j < arr1.size())
    {
        if(arr[i] >= arr1[j])
        {
            int temp = arr[i];
            arr[i] = arr1[j];
            arr1[j] = temp;
        }

        i--;
        j++;
    }

    sort(arr.begin(), arr.end());
    sort(arr1.begin(), arr1.end());

    for(int x : arr)
        cout<<x<< "  ";
    for(int x : arr1)
        cout<<x<< "  ";

    return 0;
}
