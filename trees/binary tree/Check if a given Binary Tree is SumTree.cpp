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

        int checkSumProperty(Node * root)
        {
            if(!root || (!root->left && !root->right))
                return 1;

            int ls = sum(root->left);
            int rs = sum(root->right);

            if((root->data == ls+rs) && checkSumProperty(root->left) && checkSumProperty(root->right))
                return 1;
            return 0;
        }

    private:
        int sum(Node *root)
        {
            if(!root)
                return 0;
            return sum(root->left) + root->data + sum(root->right);
        }
};

int main()
{
    BinaryTree b;
    b.insertNode(26);
    b.insertNode(10);
    b.insertNode(3);
    b.insertNode(4);
    b.insertNode(6);
    b.insertNode(3);

    cout<<b.checkSumProperty(b.root);

    return 0;
}
