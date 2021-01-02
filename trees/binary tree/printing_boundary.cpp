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

        void printBoundary()
        {
            Node* curr = root;

//            printing a left side of binary tree

            while(curr != NULL)
            {
                if(curr->left)
                {
                    cout<<curr->data<< "  ";
                    curr= curr->left;
                }
                else if(curr->right)
                {
                    cout<<curr->data<< "  ";
                    curr = curr->right;
                }
                else
                {
                    curr = NULL;
                }
            }

//            printing leaf node

            stack<Node *> q;
            q.push(root);
            while(!q.empty())
            {
                Node *temp = q.top();
                q.pop();

                if(temp->left && temp->right)
                {
                    q.push(temp->right);
                    q.push(temp->left);
                }
                else if(temp->right)
                    q.push(temp->right);

                else if(temp->left)
                    q.push(temp->left);


                else
                    cout<<temp->data<< "   ";
            }

//           printing a right side of binary tree
            curr = root->right;

            while(curr != NULL)
            {
                if(curr->right)
                {
                    cout<<curr->data<< "  ";
                    curr = curr->right;
                }
                else if(curr->left)
                {
                    cout<<curr->data<< "  ";
                    curr = curr->left;
                }
                else
                {
                    curr = NULL;
                }
            }
        }
};




int main()
{
    BinaryTree b;

    b.root = new Node(20);
    b.root->left = new Node(8);
    b.root->right = new Node(22);
    b.root->left->left = new Node(4);
    b.root->left->right = new Node(12);
    b.root->left->right->left = new Node(10);
    b.root->left->right->right = new Node(14);
    b.root->right->right = new Node(25);


    b.printBoundary();

    return 0;
}
