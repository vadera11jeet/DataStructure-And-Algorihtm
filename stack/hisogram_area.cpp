// largest rectangular area in a histogram using stack
#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int n;
    cout<< "enter size of array\n";
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
//    in this problem first of all we find the next smallest element in right and left
//    finding smallest element in left and store their index in array
    int smallRight[n];
    stack <int> st;
    st.push(n-1);
    smallRight[n-1] = n;
    for(int i=n-2; i>=0; i--)
    {
        while(!st.empty() && arr[i] < arr[st.top()])
            st.pop();

        if(st.empty())
        {
            smallRight[i] = n;
        }
        else
        {
            smallRight[i] = st.top();
        }
        st.push(i);
    }

//  now we find right smallest element for that iterate reversely and get for and store their index in another array
    int smallLeft[n];
    stack <int> st1;
    st1.push(0);
    smallLeft[0] = -1;

    for(int i=1; i<n; i++)
    {
        while(!st1.empty() && arr[i] < arr[st1.top()])
            st1.pop();

        if(st1.empty())
        {
            smallLeft[i] = -1;
        }
        else
        {
            smallLeft[i] = st1.top();
        }
        st1.push(i);
    }

    int max_ = INT_MIN;
    for(int i = 0; i<n; i++)
    {
        int value = smallRight[i] - smallLeft[i] - 1;
        int area = value * arr[i];
        if( area > max_)
            max_ = area;
    }
    cout<< max_;

    return 0;
}
