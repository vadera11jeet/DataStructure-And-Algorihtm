#include<bits/stdc++.h>
using namespace std;

// in this problem we have given 2 numbers 1 number is source number and 2 number is we want to create this number we have to find minimum step to create this number
// we are allowed to do 2 operations
// multiply number by 2 and we can reduce number by 1
// for that we use here BFS
// so we create vertex from given so we multiply number by to and check it node is created or not for that we make a visited set
// and we do same process for reduce by 1 node


// same problem on leetcode name as broken calculator https://leetcode.com/submissions/detail/459154298/

class Node
{
public:
    int value;
    int level;

    Node(int value, int level)
    {
        this->value = value;
        this->level = level;
    }
};

int minimumStepsForConvertNumber(int source, int destination)
{
    set<int> visited;

    queue<Node> q;
    q.push(Node(source, 0));

    while(!q.empty())
    {
        Node t = q.front();
        q.pop();

        if(t.value == destination)
            return t.level;

        visited.insert(t.value);
// we create value *2 node
// set return visited.end() if given value is not present in set
        if(visited.find(t.value*2) == visited.end())
        {
            Node node(t.value*2, t.level+1);
            q.push(node);
        }
// we create node for value - 1 node
        if(t.value - 1 > 0 && visited.find(t.value - 1) == visited.end())
        {
            Node node(t.value - 1,t.level+1);
            q.push(node);
        }
    }
    return INT_MAX;
}


int main()
{

    cout<<minimumStepsForConvertNumber(4, 7);

    return 0;
}
