#include<iostream>
#include<queue>
#include<vector>
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

        bool pathFinder(Node * root, vector<int> &v, int x)
        {
            if(!root)
                return false;

            v.push_back(root->data);

            if(root->data == x)
                return true;

            if(pathFinder(root->left, v, x) || pathFinder(root->right, v, x) )
                return true;

            v.pop_back();

            return false;
        }

};

void printVector(vector<int> v, bool c)
{
    if(!c)
        return;

    for(int i = 0; i<v.size(); i++)
        cout<<v[i]<<"  ";
}

int main()
{
    BinaryTree b;
    vector<int> v;

    b.insertNode(1);
    b.insertNode(2);
    b.insertNode(3);
    b.insertNode(4);
    b.insertNode(5);
    b.insertNode(6);
    b.insertNode(7);

    bool c = b.pathFinder(b.root, v, 5);
    printVector(v, c);

    return 0;
}

