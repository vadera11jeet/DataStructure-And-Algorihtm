#include<iostream>
#include<stack>
using namespace std;


void getMiddle(stack<int> & s, int mid)
{
    if(mid == 1)
    {
        cout<<s.top();
        return;
    }
    int val = s.top();
    s.pop();
    getMiddle(s, mid-1);
    s.push(val);
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int mid = s.size()/2 + 1;

    getMiddle(s, mid);

    return 0;
}
