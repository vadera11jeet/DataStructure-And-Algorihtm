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

        void inOrder(Node *root)
        {
            if(!root)
                return;
            inOrder(root->left);
            cout<<root->data<< "  ";
            inOrder(root->right);
        }

        int toSumTree(Node *node)
        {
            if(node == NULL)
                return 0;
            int oldval = node->data;

            node->data = toSumTree(node->left) + toSumTree(node->right);

            return node->data + oldval;

        }

};


int main()
{
    BinaryTree b;

    b.insertNode(10);
    b.insertNode(-2);
    b.insertNode(6);
    b.insertNode(8);
    b.insertNode(-4);
    b.insertNode(7);
    b.insertNode(5);

    cout<< "before \n";
    b.inOrder(b.root);
    cout<< "\nafter \n";
    b.toSumTree(b.root);
    b.inOrder(b.root);


    return 0;
}
