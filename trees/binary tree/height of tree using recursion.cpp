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

        int heightOfTree(Node *root)
        {
            if(root == NULL)
                return 0;

            int leftHeight = heightOfTree(root->left);
            int rightHeight = heightOfTree(root->right);

            return 1 + (leftHeight > rightHeight ? leftHeight: rightHeight);
        }

        int heightOfTree(Node *root, int level)
        {
            if(!root)
                return level;

            int leftHeight = heightOfTree(root->left, level+1);
            int rightHeight = heightOfTree(root->right, level+1);

            return leftHeight > rightHeight ? leftHeight : rightHeight;

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
    b.insertNode(4);
    b.insertNode(5);

    cout<<b.heightOfTree(b.root, 0);

    return 0;
}
