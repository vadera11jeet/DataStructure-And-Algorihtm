#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node * left, *right;
    Node(char d = INT_MIN, Node *l = NULL, Node * r = NULL)
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


        void inOrder(Node * root)
        {
            if(!root)
                return;
            inOrder(root->left);
            cout<<root->data<< "  ";
            inOrder(root->right);
        }

        void createTreeFromString(string s_)
        {
            root = new Node(s_[0]);
            int i = 1;
            stack<Node *> s;
            s.push(root);

            bool toLeft = false;
            bool toRight = false;
            for(i = 1 ; i < s_.length(); i++)
            {
                char temp = s_[i];
// for opening bracket we have to add node at the left side or right side so we make sure we have a parent node which have at least one empty side
// and it will at top of the stack
                if(temp == '(')
                {
                    while(!s.empty())
                    {
                        Node * temp1 = s.top();
                        if(!temp1->left)
                        {
                            toLeft = true;
                            break;
                        }
                        else if(!temp1->right)
                        {
                            toRight = true;
                            break;
                        }
                        else
                            s.pop();
                    }
                }
//               we add new node at top of the stack
                else if(isdigit(temp))
                {

                    Node *temp1 = s.top();
                    if(toLeft)
                    {
                        temp1->left = new Node(temp);
                        toLeft = false;
                        s.push(temp1->left);
                    }
                    else if(toRight)
                    {
                        temp1->right = new Node(temp);
                        toRight = false;
                        s.push(temp1->right);
                    }

                }
//               we pop element because that nodes don't have child or they are full
                else if(temp == ')')
                {
                    s.pop();
                }

            }
        }

        void preOrder(Node *root)
        {
            if(!root)
                return;
            cout<<root->data<< "  ";
            preOrder(root->left);
            preOrder(root->right);
        }

};


int main()
{
    BinaryTree b;

    string s = "4(2(3)(1))(6(5))";

    b.createTreeFromString(s);
    b.inOrder(b.root);
    cout<<endl;
    b.preOrder(b.root);

    return 0;
}
