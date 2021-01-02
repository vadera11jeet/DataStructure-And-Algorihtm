// in this code i used both method with stack 1) take of O(1) time using stack for In order which is inOrder()
// and second one in sum method we previously done in inorder using stack.cpp

#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int i = INT_MIN, Node * left = NULL, Node *right = NULL)
    {
        this->data = i;
        this->left = left;
        this->right = right;
    }

};

class BinaryTree
{
public:
    Node *root;
    vector <int> v;

    BinaryTree()
    {
        root = NULL;
        v.push_back(0);
    }

    void insertNode(int value)
    {
        Node *temp = new Node(value);

        if(!root)
        {
            root = temp;
            return;
        }

        queue<Node *> q;
        q.push(root);

        while(!q.empty())
        {
            Node * node = q.front();
            q.pop();

            if(node->left == NULL)
            {
                node->left = temp;
                return;
            }
            else
                q.push(node->left);

            if(node->right == NULL)
            {
                node->right = temp;
                return;
            }
            else
                q.push(node->right);
        }

    }

    void inOrder()
    {

        stack<Node*> s;
        Node *curr = root;

        while (!s.empty() || curr != NULL)
        {

            if (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            else
            {

                curr = s.top();
                s.pop();
                cout << curr->data << " ";
                v.push_back(curr->data);
                curr = curr->right;
            }
        }
        v.push_back(0);
    }

    void print_vector()
    {
        for(int i = 0; i<v.size(); i++)
            cout<<v[i]<<" ";
    }

    void sum()
    {
        Node *curr = root;

        int count_ = 1;

        stack <Node *> s;

        while(curr != NULL || !s.empty())
        {
                while(curr != NULL)
                {
                    s.push(curr);
                    curr = curr->left;
                }

                curr = s.top();
                s.pop();

                curr->data = v[count_ - 1] + v[count_ + 1];
                count_ ++;
                curr = curr->right;

        }

    }

};



int main()
{
    BinaryTree b;

    b.insertNode(1);
    b.insertNode(2);
    b.insertNode(3);
    b.insertNode(4);
    b.insertNode(5);
    b.insertNode(6);
    b.insertNode(7);

    cout<<"\nprinting value before\n";
    b.inOrder();
    cout<<endl;
    b.sum();
    cout<<"\nprinting value after\n";
    b.inOrder();




    return 0;
}
