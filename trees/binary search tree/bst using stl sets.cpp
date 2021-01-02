#include<bits/stdc++.h>
using namespace std;

// here we convert binary tree into binary search tree using STL set
// STL set implement using self balancing tree like AVL tree and red-black tree so we perform in order traversal on binary tree and store it's value in set
// and perform again in order traversal and assign set value to node's value and remove element from set

class Node
{
public:
    int data;
    Node* left, *right;

    Node(int data = INT_MIN, Node *right = NULL, Node *left = NULL)
    {
        this->data = data;
        this->right = right;
        this->left = left;
    }

};


class BinaryTree
{
    public:
        Node *root;
        set<int> s;

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
            s.insert(root->data);
            inOrder(root->right);
        }

        void setToBST(Node *root)
        {
            if(!root)
                return;
            setToBST(root->left);
            auto  it = s.begin( );
            root->data = *it;
            s.erase(it);
            setToBST(root->right);
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

    b.inOrder(b.root);
    cout<<endl;
    b.setToBST(b.root);
    b.inOrder(b.root);

    return 0;
}
