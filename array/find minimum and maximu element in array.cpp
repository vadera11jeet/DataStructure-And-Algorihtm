#include<bits/stdc++.h>
using namespace std;

void minimumMaximum(int arr[], int n, int & min_, int & max_)
{
    if(n == 1)
    {
        min_ = arr[0];
        max_ = arr[0];
        return;
    }

    if(arr[0] > arr[1])
    {
        min_ = arr[1];
        max_ = arr[0];
    }
    else
    {
        min_ = arr[0];
        max_ = arr[1];
    }

    for(int i = 2; i<n; i++)
    {
        if(arr[i] < min_)
            min_ = arr[i];

        else if(arr[i] > max_)
            max_ = arr[i];
    }
    return;
}

class MinimumMaximum
{
public:

    int min_;
    int max_;
};


MinimumMaximum tournamentMethod(int arr[], int start, int end_)
{
    MinimumMaximum min_max, mml, mmr;

    if(start == end_)
    {
        min_max.min_ = arr[start];
        min_max.max_ = arr[end_];
        return min_max;
    }

    else if(start == end_ + 1)
    {
        if(arr[start] > arr[end_])
        {
            min_max.min_ = arr[end_];
            min_max.max_ = arr[start];
        }
        else
        {
            min_max.min_ = arr[start];
            min_max.max_ = arr[end_];
        }
        return min_max;
    }

    int mid = (start + end_) / 2;
    mml = tournamentMethod(arr, start, mid);
    mmr = tournamentMethod(arr, mid+1, end_);

    if(mml.min_ < mmr.min_)
        min_max.min_ = mml.min_;
    else
        min_max.min_ = mmr.min_;

    if(mml.max_ > mmr.max_)
        min_max.max_ = mml.max_;
    else
        min_max.max_ = mmr.max_;
    return min_max;

}



int main()
{

    int arr[] = { 1000, 11, 445,
                  1, 330, 3000 };

    int max_ = INT_MIN;
    int min_ = INT_MAX;

    minimumMaximum(arr, 6, min_, max_);
    cout<<min_<< " is minimum value\n";
    cout<<max_<< " is greater value\n";

    MinimumMaximum m;

    m = tournamentMethod(arr, 0, 6-1);

    cout<< m.min_<< " min\n";
    cout<< m.max_ << " max\n";

    return 0;
}
