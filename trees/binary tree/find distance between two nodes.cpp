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

//   finding distance between 2 nodes first of all we find LCA of 2 nodes and find distance of both the node with respect to LCA and add them and return them

        int findDistance(Node *root, int n, int m)
        {
            Node *lca = findLCA(root, n, m);

            int d1 = findLevel(lca, n, 0);
            int d2 = findLevel(lca, m, 0);

            return d1 + d2;
        }

    private:

        Node *findLCA(Node * root, int n, int m)
        {
            if(!root)
                return NULL;

            if(root->data == n || root->data == m)
                return root;

            Node *left = findLCA(root->left, n, m);
            Node *right = findLCA(root->right, n, m);

            if(left && right)
                return root;

            return left != NULL ? left : right;
        }

        int findLevel(Node * root, int k, int level)
        {
            if(!root)
                return -1;

            int left = findLevel(root->left, k, level+1);

            if(root->data == k)
                return level;

            if(left == -1)
                return findLevel(root->right, k, level+1);

            return left;
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

    cout<<b.findDistance(b.root, 4 ,6);

    return 0;
}
