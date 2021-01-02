#include<iostream>
#include<stack>
#include<queue>
// reverse level like print bottom to top it is other question review it/
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

        void pairLevelTraversal()
        {
            queue <Node *> q;
            cout<< root->data<< "  ";
            q.push(root->left);
            q.push(root->right);

            while(!q.empty())
            {
                Node *temp = q.front();
                q.pop();
                Node *temp1 = q.front();
                q.pop();
                cout<<temp->data<< "  " << temp1->data<< "  " ;

                if(temp->left)
                    q.push(temp->left);
                if(temp1->right)
                    q.push(temp1->right);
                if(temp->right)
                    q.push(temp->right);
                if(temp1->left)
                    q.push(temp1->left);
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
    b.insertNode(8);
    b.insertNode(9);
    b.insertNode(10);
    b.insertNode(11);
    b.insertNode(12);
    b.insertNode(13);
    b.insertNode(14);
    b.insertNode(15);

    b.pairLevelTraversal();


    return 0;
}
