#include<iostream>
#include<stack>
using namespace std;

void insert_(stack<int> &s, int val)
{
    if(s.empty() || s.top()<= val)
    {
        s.push(val);
        return;
    }
    int a = s.top();
    s.pop();
    insert_(s, val);
    s.push(a);
}


void sort_(stack <int> & s)
{
    if(s.empty())
        return;
    int val = s.top();
    s.pop();
    sort_(s);
    insert_(s, val);
}

int main()
{
    stack<int> s;

    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    sort_(s);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
