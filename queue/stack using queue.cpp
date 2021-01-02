#include<iostream>
#include<stack>
using namespace std;



int main()
{
    stack <int> s1, s2;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s2.pop();
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }

    while(!s1.empty())
    {
        cout<<s1.top()<<endl;
        s1.pop();
    }

    return 0;
}
