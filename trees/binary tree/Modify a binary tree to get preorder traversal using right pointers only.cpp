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

        void inOrdereByRightPointer()
        {
            Node * curr = root;
            stack<Node *> s;
            s.push(root);
            Node *pre = NULL;
            while(!s.empty())
            {
                Node * temp = s.top();
                s.pop();
                if(temp->right)
                    s.push(temp->right);
                if(temp->left)
                    s.push(temp->left);

                if(pre)
                    pre->right = temp;
                pre = temp;

            }

            Node *temp = root;
            while(temp != NULL)
            {
                cout<<temp->data<< "  ";
                temp = temp->right;
            }

        }
};


int main()
{
    BinaryTree b;
    b.root = new Node(10);
    b.root->left = new Node(8);
    b.root->right = new Node(2);
    b.root->left->left = new Node(3);
    b.root->left->right = new Node(5);

    b.inOrdereByRightPointer();

    return 0;
}
