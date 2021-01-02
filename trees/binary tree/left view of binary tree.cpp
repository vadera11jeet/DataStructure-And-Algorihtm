#include<bits/stdc++.h>
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

        void inOrder(Node * root)
        {
            if(!root)
                return;
            inOrder(root->left);
            cout<<root->data<< "  ";
            inOrder(root->right);
        }

//        first element of level order traversal of binary tree gives you

        void leftViewOfBinaryTree()
        {
            queue<Node *> q;
            q.push(root);
            int count_ = 0;
            q.push(NULL);
            cout<<root->data<< "  ";
            while(q.size() > 1)
            {
                Node *temp = q.front();
                q.pop();
                if(temp == NULL)
                {
                    cout<<q.front()->data<< "  ";
                    q.push(NULL);
                }

                else
                {
                    if(temp->left)
                        q.push(temp->left);

                    if(temp->right)
                        q.push(temp->right);
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

    b.leftViewOfBinaryTree();

    return 0;
}
