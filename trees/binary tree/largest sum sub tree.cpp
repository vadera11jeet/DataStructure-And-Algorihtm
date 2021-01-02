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

        int findLargestSumSubTree(Node *root, int &ans)
        {
            if(!root)
                return 0;
// sum all the sub tree in pre order
            int curr = root->data + findLargestSumSubTree(root->left, ans) +  findLargestSumSubTree(root->right, ans);
//          and finding maximum sum
            ans = max(curr, ans);
            return curr;
        }

};

int main()
{
    BinaryTree b;

    b.insertNode(1);
    b.insertNode(-2);
    b.insertNode(3);
    b.insertNode(4);
    b.insertNode(5);
    b.insertNode(-6);
    b.insertNode(2);

    int temp = INT_MIN;

    cout<<b.findLargestSumSubTree(b.root,temp);

    return 0;
}
