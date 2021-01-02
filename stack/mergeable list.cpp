#include<iostream>
#include<stack>
// this lib is use for getting sort function
#include<algorithm>
using namespace std;

struct Interval
{
    int start;
    int end_;
};

bool compar(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}


int main()
{
     Interval arr [] = { {22,28}, {1,8}, {25,27}, {14,19}, {27, 30} , {5, 12} };
     int n = sizeof(arr) / sizeof(arr[0]);
     stack <Interval> st;
     sort(arr, arr+n, compar);
     st.push(arr[0]);
     for(int i = 1; i<n ; i++)
     {
        Interval top = st.top();
        if(top.end_ >= arr[i].start)
        {
            if(top.end_ < arr[i].end_)
            {
                st.pop();
                top.end_ = arr[i].end_;
                st.push(top);
            }
        }
        else
        {
            st.push(arr[i]);
        }
     }

     while(!st.empty())
     {
         Interval t = st.top();
         cout << t.start << "  " << t.end_<<endl;
         st.pop();
     }


    return 0;
}
