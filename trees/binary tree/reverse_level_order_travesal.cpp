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


        void levelRevese()
        {
            queue <Node*> q;
            stack <Node*> s;
            q.push(root);
            while(!q.empty())
            {
                Node *temp = q.front();
                q.pop();
                s.push(temp);

                if(temp->right)
                  q.push(temp->right);

                if(temp->left)
                     q.push(temp->left);

            }

            while(!s.empty())
            {
                Node *temp = s.top();
                cout<<temp->data<< "  ";
                s.pop();
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

    b.levelRevese();

    return 0;
}


