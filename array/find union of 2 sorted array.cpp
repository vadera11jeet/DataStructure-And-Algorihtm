#include<bits/stdc++.h>
using namespace std;



void unionOFArray(int arr[], int arr1[], int m, int n)
{
    set <int> s;

    for(int i = 0; i<m; i++)
        if(s.find(arr[i]) == s.end())
            s.insert(arr[i]);
    for(int i = 0; i<n; i++)
        if(s.find(arr1[i]) == s.end())
            s.insert(arr1[i]);

    cout<< "this is union size is : "<<s.size();

    cout<<endl;
    for(auto x : s)
        cout<< x<< "  ";
    cout<<endl;
}



int main()
{
    int arr1 [] = { 1, 2, 4, 5, 6 } ;
    int arr2[] = { 2, 3, 5, 7 };

    unionOFArray(arr1, arr2, 6, 4);

    return 0;
}
