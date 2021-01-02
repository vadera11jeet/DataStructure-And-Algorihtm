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

        int findingLowestCommanAncestor(Node * root, int n, int m)
        {
            if(!root)
                return INT_MIN;

//        if root equal to given value then return root data else we find to it right child and left child
            if(root->data == n || root->data == m)
                return root->data;

            int left = findingLowestCommanAncestor(root->left, n, m);
            int right = findingLowestCommanAncestor(root->right, n, m);

//          if both the side of root not returning int min value than that is root is LCA
            if(left != INT_MIN && right != INT_MIN)
                return root->data;

//          else return one of them this case for parent child node
            return left != INT_MIN ? left : right;

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


//    if LCA is equal to INT_MIN that mean either one node is not exist in tree or both of nodes are not present in binary tree
    cout<<b.findingLowestCommanAncestor(b.root, 4, 5);

    return 0;
}
