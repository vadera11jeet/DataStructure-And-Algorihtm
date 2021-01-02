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

        void inOrderUsingStack()
        {
            stack <Node *> s;
            Node *curr = root ;

            while(curr != NULL || !s.empty())
            {
                while(curr != NULL)
                {
                    s.push(curr);
                    curr = curr->left;
                }

                curr = s.top();
                s.pop();

                cout<<curr->data << " ";
                curr = curr->right;

            }

        }

    void inOrder()
    {

        stack<Node*> s;
        Node *curr = root;

        while (!s.empty() || curr != NULL)
        {

            if (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            else
            {

                curr = s.top();
                s.pop();
                cout << curr->data << " ";
                curr = curr->right;
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

    cout<< "with order of O(n^2) in time \n" ;
    b.inOrderUsingStack();
    cout<<endl;
    cout << "with order of O(n) in time \n";
    b.inOrder() ;
    cout<<endl;

    return 0;
}
