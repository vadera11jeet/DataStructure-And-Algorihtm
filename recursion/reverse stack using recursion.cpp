#include<iostream>
#include<stack>
using namespace std;

void insert_(stack<int> & s, int val)
{
    if(s.size() == 0)
    {
        s.push(val);
        return;
    }
    int a = s.top();
    s.pop();
    insert_(s,val);
    s.push(a);

}

void reverseStack(stack<int> & s)
{
    if(s.empty())
        return;
    int val = s.top();
    s.pop();
    reverseStack(s);
    insert_(s, val);

}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverseStack(s);

    while(!s.empty())
    {
        cout<<s.top()<< "  ";
        s.pop();
    }

    return 0;
}
