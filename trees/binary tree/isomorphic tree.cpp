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


};
bool checkForIsomorphic(Node *t, Node *t2)
{
    if(!t && !t2)
        return true;

    if(t == NULL || t2 == NULL)
        return false;

    if(t->data != t2->data)
        return false;

    if((checkForIsomorphic(t->left, t2->left) && checkForIsomorphic(t->right , t2->right)) ||
        (checkForIsomorphic(t->left , t2->right) && checkForIsomorphic(t->right, t2->left)))
            return true;
}



int main()
{
    BinaryTree b;
    Node *n1 = new Node(1);
    n1->left = new Node(2);
    n1->right = new Node(3);
    n1->left->left  = new Node(4);
    n1->left->right = new Node(5);
    n1->right->left  = new Node(6);
    n1->left->right->left = new Node(7);
    n1->left->right->right = new Node(8);


    Node *n2 = new Node(1);
    n2->left         = new Node(3);
    n2->right        = new Node(2);
    n2->right->left   = new Node(4);
    n2->right->right   = new Node(5);
    n2->left->right   = new Node(6);
    n2->right->right->left = new Node(8);
    n2->right->right->right = new Node(7);

    cout<<checkForIsomorphic(n1, n2);

    return 0;
}
