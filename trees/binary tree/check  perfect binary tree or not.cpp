#include<iostream>
#include<queue>
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


     bool checkPerfectBinaryTree(Node *root, int level=0)
     {
         int d = findDepth(root);

         return checkPerfect(root, d, level);
     }


    private:

        int findDepth(Node *root)
        {
            int d = 0;
            while(root)
            {
                d++;
                root = root->left;
            }
            return d;
        }

        bool checkPerfect(Node *root, int d , int level = 0)
        {
            if(!root)
                return true;
            if(!root->left && !root->right)
                return (d == level+1);
            if(!root->left || !root->right)
                return false;
            return checkPerfect(root->left, d, level + 1) && checkPerfect(root->right, d , level+1);
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

    cout<< b.checkPerfectBinaryTree(b.root);

    return 0;
}



