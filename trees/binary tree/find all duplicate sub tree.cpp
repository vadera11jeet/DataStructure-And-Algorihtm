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

        string inOrder(Node * root, unordered_map<string, int> &m)
        {
            if(!root)
                return "";

            string s = "(";
            s += inOrder(root->left, m);
            s += to_string(root->data);
            s += inOrder(root->right,m);
            s += ")";

            if(m[s] == 1)
                cout<<root->data<< "  ";

            m[s]++;
            return s;
        }
};

int main()
{
    BinaryTree b;

    b.root = new Node(1);
    b.root->left = new Node(2);
    b.root->right = new Node(3);
    b.root->left->left = new Node(4);
    b.root->right->left = new Node(2);
    b.root->right->left->left = new Node(4);
    b.root->right->right = new Node(4);

    unordered_map<string, int> m;

    b.inOrder(b.root, m);

    return 0;
}
