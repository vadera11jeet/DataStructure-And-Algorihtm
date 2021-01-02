#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack <int> st, st1;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    int n = (st.size() + 1) / 2;
    for(int i = 0; i<n-1; i++)
    {
        st1.push(st.top());
        st.pop();
    }

    st.pop();
    while(!st1.empty())
    {
        st.push(st1.top());
        st1.pop();
    }
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}
