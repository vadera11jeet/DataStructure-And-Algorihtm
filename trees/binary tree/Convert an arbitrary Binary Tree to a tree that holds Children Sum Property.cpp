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

        void convertTree(Node * node)
        {
            int rightData = 0, leftData = 0, diff;
            if(!node || (!node->left && !node->right))
                return;

            else
            {
                convertTree(node->left);
                convertTree(node->right);

                if(node->left)
                    leftData = node->left->data;
                if(node->right)
                    rightData = node->right->data;

                diff = leftData + rightData - node->data;

                if(diff > 0)
                    node->data += diff;

                if(diff < 0)
                    increment(node, -diff);
            }

        }

    private:
        void increment(Node *node , int diff)
        {
            if(node->left)
            {
                node->left->data += diff;
                increment(node->left, diff);
            }
            else if(node->right)
            {
                node->right->data += diff;
                increment(node->right, diff);
            }
        }
};

int main()
{
    BinaryTree b;

    b.insertNode(50);
    b.insertNode(7);
    b.insertNode(2);
    b.insertNode(3);
    b.insertNode(5);
    b.insertNode(1);
    b.insertNode(30);

    cout<< "before \n";
    b.inOrder(b.root);
    cout<< "\nafter \n";
    b.convertTree(b.root);
    b.inOrder(b.root);

    return 0;
}
