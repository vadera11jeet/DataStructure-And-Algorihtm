#include<iostream>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node *right, *left;

    Node(int data = INT_MIN, Node *right = NULL, Node *left = NULL)
    {
        this->data = data;
        this->right = right;
        this->left = left;
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

    void mirrorTree()
    {
        if(!root)
            return;

        queue <Node *> q;
        q.push(root);

        while(!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if(temp)
            {
                if(temp->right)
                    q.push(temp->right);
                if(temp->left)
                    q.push(temp->left);

                Node *temp1 = temp->left;
                temp->left = temp->right;
                temp->right = temp1;

            }
            else
                break;

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

};

int main()
{
    BinaryTree b;

    b.insertNode(1);
    b.insertNode(2);
    b.insertNode(3);
    b.insertNode(4);
    b.insertNode(5);


    cout<< "before mirroring \n";
    b.inOrder(b.root);

    cout<< "\nafter mirroring\n";
    b.mirrorTree();
    b.inOrder(b.root);

    return 0;
}
