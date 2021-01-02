#include<bits/stdc++.h>
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

        vector<int> longestPath(Node *root)
        {
            if(!root)
            {
                vector<int> temp = {};
                return temp;
            }
//            finding path both side
            vector<int> rightpath = longestPath(root->right);
            vector<int> leftpath = longestPath(root->left);

//            which path has more element at that path we add next element as per we want to find smallest path

            if(leftpath.size() > rightpath.size())
                leftpath.push_back(root->data);
            else
                rightpath.push_back(root->data);

//          returning largest path
            return leftpath.size() > rightpath.size() ? leftpath : rightpath ;

        }
};

int main()
{

    BinaryTree b;

    b.insertNode(1);
    b.insertNode(2);
    b.insertNode(3);
    b.insertNode(4);


    vector<int> a = b.longestPath(b.root);

//  this will print all element from leaf to root

    for(auto i:a)
        cout<<i<<"  ";

    return 0;
}
