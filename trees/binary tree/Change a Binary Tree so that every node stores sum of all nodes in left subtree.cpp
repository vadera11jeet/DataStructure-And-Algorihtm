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

        void inOrder(Node *root)
        {
            if(!root)
                return;
            inOrder(root->left);
            cout<<root->data<< "  ";
            inOrder(root->right);
        }

        void leftSum(Node * node)
        {
            if(!node)
                return;


            stack <Node*> s;
            int sum = 0;
            Node *temp = node;

            while(temp)
            {
                s.push(temp);
                temp = temp->left;
            }

            sum += s.top()->data;
            s.pop();

            while(!s.empty())
            {
                Node *temp1 = s.top();
                s.pop();
                int temp2 = temp1->data ;
                sum += temp2;
                temp1->data = sum;
                 Node *right = temp1->right;
                 sum += right->data;

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

    cout<< "before \n";
    b.inOrder(b.root);
    cout<< "\nafter\n";
    b.leftSum(b.root);
    b.inOrder(b.root);

    return 0;
}
