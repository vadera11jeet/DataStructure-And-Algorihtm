//morris traversal is method which is used for tree traversal and this method is not use recursion and stack
// this method give output in order O(1) extra space

// working of this algorithm is we used leaf node's free space and point to in order manner
// first of all we go right most element of left sub tree and assign it's right pointer to successor element from in order traversal

// algorithm
// current element has value of root pointer
// then check current->left is exist or not if don't exist then print current value and current point to current->right else follow below process
// value of current assign to previous and go to the right most element of left subtree
// for that we use loop with condition previous->right != NULL and previous->right != current
// then we check if right most element of left sub tree's right pointer is NULL or not if it is null then we assign to successor element from in order traversal
// if that element is already pointing to successor element from in order traversal that means we visit this node and make it's right pointer NULL as it is and print current pointer value

#include<iostream>
#include<queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data = INT_MIN, Node *left = NULL, Node * right = NULL)
    {
        this->data = data;
        this->left = left;
        this->right = right;
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

    void morris_inorder_traversal()
    {

        if(!root)
            return;

        Node *curr = root; //here we assign root to current pointer
        Node *prev;
        while(curr)
        {
            if(!curr->left)
            {
                cout<<curr->data<< " ";
                curr = curr->right;
            }
            else
            {
                prev = curr->left;
                while(prev->right != NULL && prev->right != curr)
                {
                    prev = prev->right;
                }

                if(!prev->right)
                {
                    prev->right = curr;
                    curr = curr->left;
                }

                if(prev->right == curr)
                {
                    prev->right = NULL;
                    cout<<curr->data<< " ";
                    curr = curr->right;
                }
            }
        }

    }


    void nodeInsert(int value)
    {
        Node * node = new Node(value);

        if(!root)
        {
            root = node;
            return;
        }

        queue <Node *> q;
        q.push(root);

        while(!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if(temp->left == NULL)
            {
                temp->left = node;
                return;
            }
            else
                q.push(temp->left);

            if(temp->right == NULL)
            {
                temp->right = node;
                return;
            }
            else
                q.push(temp->right);

        }
    }
};


int main()
{

    BinaryTree b;
    b.nodeInsert(1);
    b.nodeInsert(2);
    b.nodeInsert(3);
    b.nodeInsert(4);
    b.nodeInsert(5);
    b.nodeInsert(6);
    b.nodeInsert(7);

    b.morris_inorder_traversal();

    return 0;
}


