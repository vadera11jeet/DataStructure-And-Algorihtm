#include<bits/stdc++.h>
using namespace std;

void rotationArray(int arr[], int n, int k)
{
    for(int i = 0; i<n; i++)
    {
        cout<< arr[(n - k +i)%n]<< "  ";
    }
}
int main()
{
    int arr [] = {1, 2, 3, 4, 5};

    rotationArray(arr, 5, 1);
    cout<<endl;


    return 0;
}
