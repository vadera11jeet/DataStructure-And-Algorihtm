#include<iostream>
#include<queue>
using namespace std;

void reverseQueue(queue <int> &q)
{
    if(q.empty())
        return;
    int temp = q.front();
    q.pop();
    reverseQueue(q);
    q.push(temp);
}

int main()
{
    queue <int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseQueue(q);
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }

    return 0;
}
