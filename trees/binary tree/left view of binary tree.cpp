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

//    first element of level order traversal of binary tree gives you left sub tree of binary tree
//    so here we use level order traversal to and we find first element of every level and print it's value
//    here we find null in queue that means one level of tree is completed and we start new level and print a value

        void leftViewOfBinaryTree()
        {
            queue<Node *> q;
            q.push(root);
            int count_ = 0;
            q.push(NULL);
            cout<<root->data<< "  ";
            while(q.size() > 1)
            {
                Node *temp = q.front();
                q.pop();
                if(temp == NULL)
                {
                    cout<<q.front()->data<< "  ";
                    q.push(NULL);
                }

                else
                {
                    if(temp->left)
                        q.push(temp->left);

                    if(temp->right)
                        q.push(temp->right);
                }

            }

        }
//     this approach is optimized approach in terms of space complexity this approach take space of O(depth of tree) above approach take O(n) space

        void leftViewUtil(Node *root, int height, vector<bool> &level, vector<int>& vec)
        {
            if(!root)
                return;

            if(level[height] == false)
            {
                vec.push_back(root->data);
                level[height] = true;
            }

            leftViewUtil(root->left, height + 1, level, vec);
            leftViewUtil(root->right, height + 1, level, vec);

        }


        vector<int> leftView(Node *root)
        {
           // Your code here
           vector<bool> level(100, false);
           vector<int> ans;

           int height = 0;

           leftViewUtil(root, height, level, ans);

           return ans;


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

    b.leftViewOfBinaryTree();

    return 0;
}
