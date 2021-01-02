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


        void inOrder(Node *temp)
        {
            if(!temp)
                return;
            inOrder(temp->left);
            cout<<temp->data<<"  ";
            inOrder(temp->right);
        }

        void preOrder(Node *temp)
        {
            if(!temp)
                return;

            cout<<temp->data<<"  ";
            preOrder(temp->left);
            preOrder(temp->right);
        }

        void postOrder(Node *temp)
        {
            if(!temp)
                return;

            postOrder(temp->left);
            postOrder(temp->right);
            cout<<temp->data<<"  ";
        }

        void levelOrder()
        {
            if(!root)
                return;

            queue <Node*> q;
            q.push(root);

            while(!q.empty())
            {
                Node *temp = q.front();
                cout<<temp->data<<"  ";
                q.pop();

                if(temp->left)
                {
                    q.push(temp->left);
                }

                if(temp->right)
                {
                    q.push(temp->right);
                }

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

    cout<< "inorder traversal\n";
    b.inOrder(b.root);
    cout<< "\npreorder traversal\n";
    b.preOrder(b.root);
    cout<< "\npostorder traversal\n";
    b.postOrder(b.root);
    cout<< "\nlevelorder traversal\n";
    b.levelOrder();

    return 0;
}
