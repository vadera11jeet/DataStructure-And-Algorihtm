#include<iostream>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node *right, *left;

    Node(int d = INT_MIN, Node *right = NULL, Node *left = NULL)
    {
        data = d;
        this->right = right;
        this->left = left;
    }
};

class BinaryTree
{
public:
    Node * root;
    BinaryTree()
    {
        root = NULL;
    }

    void insertNode(int data)
    {
        Node *temp = new Node(data);
        if(root == NULL)
        {
            root = temp;
            return;
        }
        queue <Node *> q;
        q.push(root);

        while(!q.empty())
        {
            Node *temp1 = q.front();
            q.pop();

            if(temp1->left == NULL)
            {
                temp1->left = temp;
                return;
            }
            else
                q.push(temp1->left);

            if(temp1->right == NULL)
            {
                temp1->right = temp;
                return;
            }
            else
                q.push(temp1->right);

        }
    }

    void inOrderTraversal(Node *temp)
    {
        if(temp == NULL)
            return;

        inOrderTraversal(temp->left);
        cout<<temp->data<<" ";
        inOrderTraversal(temp->right);
    }

    void deleteNode(int value)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
        {
            if(root->data == value)
            {
                root = NULL;
                return;
            }
            else
            {
                root = root;
                return;
            }
        }

        queue <Node *> q;
        q.push(root);

        Node *temp;
        Node * current_node = NULL;

        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(temp->data == value)
                current_node = temp;
            if(temp->right)
                q.push(temp->right);
            if(temp->left)
                q.push(temp->left);
        }

        if(current_node != NULL)
        {
            int val = temp->data;
            deleteDeepes(temp);
            current_node->data = val;
        }
    }

private:
    void deleteDeepes(Node * del)
    {
        queue<Node *> q;
        q.push(root);
        Node * temp;

        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(temp == del)
            {
                temp = NULL;
                delete(del);
                return;
            }

            if(temp->right)
            {
                if(temp->right == del)
                {
                    temp->right = NULL;
                    delete(del);
                    return;
                }
                else
                    q.push(temp->right);
            }

            if(temp->left)
            {
                if(temp->left == del)
                {
                    temp->left = NULL;
                    delete(del);
                    return;
                }
                else
                    q.push(temp->left);
            }

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

    b.inOrderTraversal(b.root);

    b.deleteNode(6);
    b.deleteNode(1);

    cout<<endl;
    b.inOrderTraversal(b.root);

    return 0;
}
