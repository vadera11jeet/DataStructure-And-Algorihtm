#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack <int> st, st1;

    st.push(34);
    st.push(-3);
    st.push(31);
    st.push(98);
    st.push(92);
    st.push(23);

    while(!st.empty())
    {
        int value = st.top();
        st.pop();
        while(!st1.empty() &&  value < st1.top())
        {
            st.push(st1.top());
            st1.pop();
        }
        st1.push(value);
    }
    while(!st1.empty())
    {
        cout<<st1.top()<<endl;
        st1.pop();
    }

    return 0;
}
