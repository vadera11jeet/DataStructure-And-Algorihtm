#include<iostream>
#include<queue>
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

        bool checkSumProperty()
        {
            queue <Node*> q;
            q.push(root);

            while(!q.empty())
            {
                int data = 0;
                Node *temp = q.front();
                q.pop();

                if(temp->left && temp->right)
                {
                    if(temp->data == (temp->left->data + temp->right->data))
                    {
                        q.push(temp->left);
                        q.push(temp->right);
                    }
                    else
                        return false;
                }
                else if(temp->left)
                {
                    if(temp->data == temp->left->data)
                        q.push(temp->left);
                    else
                        return false;
                }
                else if(temp->right)
                {
                    if(temp->data == temp->right->data)
                        q.push(temp->right);
                    else
                        return false;
                }

            }
            return true;
        }
};

int main()
{
    BinaryTree b;

    b.insertNode(10);
    b.insertNode(8);
    b.insertNode(2);
    b.insertNode(3);
    b.insertNode(5);
    b.insertNode(2);

    cout<< b.checkSumProperty();

    return 0;
}
