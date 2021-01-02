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


//    right view of binary tree is last element of level order traversal in all laer

        void rightViewOfTree()
        {
            queue<Node *> q;
            q.push(root);
            q.push(NULL);

            while(q.size() > 1)
            {
                Node *temp = q.front();
                q.pop();

                if(!temp)
                {
                    q.push(NULL);
                    continue;
                }
                if(!q.front())
                    cout<<temp->data<< "  ";

                if(temp->left)
                    q.push(temp->left);

                if(temp->right)
                    q.push(temp->right);

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

    b.rightViewOfTree();

    return 0;
}
