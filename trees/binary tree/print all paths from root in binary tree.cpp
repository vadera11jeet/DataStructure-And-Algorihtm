#include<iostream>
#include<queue>
#include <string>
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

            void printAllPaths(Node *root, string path)
            {
                if(!root)
                    return;
                if(!root->left && !root->right)
                {
                    cout<<path<<endl;
                    return;
                }
                string op1 = path;
                string op2 = path;

                if(root->left)
                {
                    op1.push_back(' ');
                    op1 = op1 + to_string(root->left->data);
                }

                if(root->right)
                {
                    op2.push_back(' ');
                    op2 = op2 + to_string(root->right->data);
                }

                printAllPaths(root->left, op1);
                printAllPaths(root->right, op2);
            }

//       this is more memory efficient approach because here we pass temp vector as reference
         void pathsUtil(Node * root, vector<vector<int>> & ans, vector<int> & temp)
         {

            if(root == NULL)
                return;

            temp.push_back(root->data);

            if(root->left == NULL && root->right == NULL)
            {
                ans.push_back(temp);
                return;
            }

            if(root->left)
            {
                pathsUtil(root->left, ans, temp);
                temp.pop_back();
            }
            if(root->right)
            {
                pathsUtil(root->right, ans, temp);

                temp.pop_back();

            }
            return;
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

    string s = to_string(b.root->data);
    b.printAllPaths(b.root,s);
    return 0;
}
