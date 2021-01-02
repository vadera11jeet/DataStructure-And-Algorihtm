#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node
{
public:
    int data;
    Node * left, *right;
    Node(int d = INT_MIN, Node *l = NULL, Node * r = NULL)
    {
        data = d;
        left = l;
        right = r;
    }
};

class BinaryTree
{
    public:
        Node *root;

        BinaryTree()
        {
            root = NULL;
        }

        void insertNode(int value)
        {
            Node * temp1 = new Node(value);


            if(root == NULL)
            {
                root = temp1;
                return;
            }

            queue <Node*> q;
            q.push(root);

            while(!q.empty())
            {
                Node * temp = q.front();
                q.pop();

                if(temp->left != NULL)
                    q.push(temp->left);
                else
                {
                    temp->left = temp1;
                    return;
                }

                if(temp->right != NULL)
                    q.push(temp->right);
                else
                {
                    temp->right = temp1;
                    return;
                }
            }
        }

        void levelTraversalSpiral()
        {
            stack <Node*> s1, s2;
            s1.push(root);

            while(!s1.empty() || !s2.empty())
            {
                while(!s1.empty())
                {
                    Node *temp = s1.top();
                    s1.pop();
                    cout<<temp->data<< "  ";
                    if(temp->left)
                        s2.push(temp->left);
                    if(temp->right)
                        s2.push(temp->right);
                }

                while(!s2.empty())
                {
                    Node *temp1 = s2.top();
                    s2.pop();
                    cout<<temp1->data<< "  ";
                    if(temp1->right)
                        s1.push(temp1->right);
                    if(temp1->left)
                        s1.push(temp1->left);
                }

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

    b.levelTraversalSpiral();

    return 0;
}
