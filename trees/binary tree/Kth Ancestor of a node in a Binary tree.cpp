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
        Node *temp;

        BinaryTree()
        {
            root = NULL;
            temp = NULL;
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


        Node * kthAncestor(Node * root, int value, int &key)
        {
            if(!root)
                return NULL;
//           for finding k th ancestor we find all till left most node and right most node or root's data is equal to given data
            if(root->data == value || (temp = kthAncestor(root->left, value, key)) || (temp = kthAncestor(root->right, value, key)))
            {
                if(key > 0)
                    key--;
                else if(key == 0)
                {
                    cout<<root->data;
                    return NULL;
                }
                return root;
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





    int k = 2;
    Node * temp = b.kthAncestor(b.root, 4, k);
    if(temp)
        cout<<temp->data;

    return 0;
}
