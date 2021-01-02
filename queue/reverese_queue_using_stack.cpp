#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    stack <int> st;
    queue <int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    for(int i = 0; i<5; i++)
    {
        st.push(q.front());
        q.pop();
    }

    for(int i = 0; i<5; i++)
    {
        q.push(st.top());
        st.pop();
    }

    for(int i = 0; i<5;i++)
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}
