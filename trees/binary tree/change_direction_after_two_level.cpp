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

        void switchAfterTwoDirection()
        {

            if(!root)
                return;

            queue <Node *> q;
            stack <Node *> s;
            bool rightToLeft = false;
            q.push(root);
            int count_ = 0;
            Node *temp ;

            while(!q.empty())
            {
                count_++;
                int ss = q.size();
                for(int i = 0; i<ss ;i++)
                {
                    temp = q.front();
                    q.pop();
                    if(!rightToLeft)
                    {
                        cout<<temp->data<< "  ";
                    }
                    else
                    {
                        s.push(temp);
                    }
                    if(temp->left)
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right);
                }

                if(rightToLeft)
                {
                    while(!s.empty())
                    {
                        temp = s.top();
                        s.pop();
                        cout<<temp->data<< "  ";

                    }
                }

                if(count_ == 2)
                {
                    rightToLeft = !rightToLeft;
                    count_ = 0;
                }
                cout<<endl;
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
    b.insertNode(8);
    b.insertNode(9);
    b.insertNode(10);
    b.insertNode(11);
    b.insertNode(12);
    b.insertNode(13);
    b.insertNode(14);
    b.insertNode(15);
    b.insertNode(16);
    b.insertNode(17);

    b.switchAfterTwoDirection();

    return 0;
}
