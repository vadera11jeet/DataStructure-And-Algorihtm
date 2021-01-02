#include<bits/stdc++.h>
using namespace std;

// diameter of tree is the largest distance between the 2 nodes and it is not necessary it will pass through root
// either it will pass through root or it won't
// diameter = height of left subtree + height of right subtree + 1 here + 1 for a parent node of the left & right subtree


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


//     this function take O(n^2) time to execute we can optimize it by using this function to calculate height in the same function
        int diameterOfTree(Node * root)
        {
            if(!root)
                return 0;

            int leftSubTreeHeight = heightOfTree(root->left, 0);
            int rightSubTreeHeight = heightOfTree(root->right, 0);

            int leftDiameter = diameterOfTree(root->left);
            int rightDiameter = diameterOfTree(root->right);

            return max(leftSubTreeHeight + rightSubTreeHeight +1, max(leftDiameter, rightDiameter));
        }


// optimize function for finding diameter of tree

        int diameter(Node *root, int &height)
        {

            if(!root)
            {
                height = 0;
                return 0;
            }

            int leftSubTreeHeight = 0;
            int rightSubTreeHeight = 0 ;

            int lefSubTreeDiameter = diameter(root->left, leftSubTreeHeight);
            int rightSubTreeDiameter = diameter(root->right, rightSubTreeHeight);

            height = max(leftSubTreeHeight, rightSubTreeHeight) + 1;

            return max(leftSubTreeHeight + rightSubTreeHeight +1, max(lefSubTreeDiameter, rightSubTreeDiameter));

        }

    private:

        int heightOfTree(Node *root, int level)
        {
            if(!root)
                return level;

            int leftHeight = heightOfTree(root->left, level+1);
            int rightHeight = heightOfTree(root->right, level+1);

            return leftHeight > rightHeight ? leftHeight : rightHeight;

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

    int a = 0;
    cout<<b.diameter(b.root, a);

    return 0;
}
