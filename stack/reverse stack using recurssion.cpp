#include<iostream>
#include<stack>
using namespace std;

// this function is pushed value in stack by specific manner if stack is empty then it add element directly else it pop all the present element
// then push given element and push all poped element


void insertAtLast(stack <int> &st, int value)
{
    if(st.empty())
    {
        st.push(value);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtLast(st, value);
    st.push(temp);

}
// first of all we remove all the element from the stack and try them to insert

void reverse_(stack <int> & st)
{
    if(st.empty())
        return;
    int temp = st.top();
    st.pop();
    reverse_(st);
    insertAtLast(st, temp);
}

int main()
{
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<< "without reversed stack \n";
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    cout<< "reversed stack\n";
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverse_(st);
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}
