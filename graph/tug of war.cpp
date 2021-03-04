#include<bits/stdc++.h>
#include<cmath>
using namespace std;

// this is backtrack problem it this problem you make an equal size partition of a given array such that the difference of each partition is minimum

int mindiff = INT_MAX;
vector<int> s1;
vector<int> s2;
void tugOfWar(vector<int> arr, int currIndex, vector<int> &set1, vector<int> & set2, int sum1, int sum2)
{

    if(currIndex == arr.size())
    {
        int delta = abs(sum1 - sum2);

        if(delta < mindiff)
        {
            mindiff = delta;
            s1.clear();
            s2.clear();
            for(int i : set1)
                s1.push_back(i);
            for(int i : set2)
                s2.push_back(i);

        }
        return ;
    }

//  here we optimize code we stop calling function if one partition has more than half element in array because we have to create to equal size partiton
    if(set1.size() < (arr.size() + 1)/2)
    {
        set1.push_back(arr[currIndex]);
        tugOfWar(arr, currIndex+1, set1, set2, sum1+arr[currIndex], sum2);
        set1.pop_back();
    }

    if(set2.size() < (arr.size() + 1)/2)
    {
        set2.push_back(arr[currIndex]);
        tugOfWar(arr, currIndex+1, set1, set2, sum1, sum2+arr[currIndex]);
        set2.pop_back();
    }

}


int main()
{

    vector<int> arr = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};

    vector<int> set1, set2;

    tugOfWar(arr, 0, set1, set2, 0, 0);



    cout<<endl;

    for(int i : s1)
        cout<<i<< "  ";

    cout<<endl;

    for(int i : s2)
        cout<<i<< "  ";


    return 0;
}
