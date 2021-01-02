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

//        first element in vertical traversal gives you top view of binary tree

        void topViewTree()
        {
            int height = 0;
            queue<pair<Node*, int>> q;
            map<int, vector<int>> m;
            q.push(make_pair(root, height));
            while(!q.empty())
            {
                pair<Node*, int> temp = q.front();
                q.pop();

                Node * n = temp.first;
                int h = temp.second;

                m[h].push_back(n->data);

                if(n->left)
                    q.push(make_pair(n->left, h - 1));
                if(n->right)
                    q.push(make_pair(n->right, h + 1));

            }

            map<int,vector<int>>::iterator it;
            for(it = m.begin(); it != m.end(); it++)
            {
                cout<<it->second[0]<< "  ";
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

    b.topViewTree();

    return 0;
}
