#include<iostream>
#include<stack>
using namespace std;

void sortStack(stack <int> & st, int value)
{
    if(st.empty())
    {
        st.push(value);
        return;
    }
    int temp = st.top();
    if(temp < value)
    {
        st.push(value);
    }
    else
    {
        st.pop();
        sortStack(st, value);
        st.push(temp);
    }

}

void sort_(stack <int> &st)
{
    if(st.empty())
        return;
    int value = st.top();
    st.pop();
    sort_(st);
    sortStack(st, value);
}

int main()
{
    stack <int> st;
    st.push(30);
    st.push(-5);
    st.push(18);
    st.push(14);
    st.push(-3);
    sort_(st);
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}
