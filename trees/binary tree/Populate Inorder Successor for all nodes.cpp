#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

class Node
{
public:
    int data;
    Node * right;
    Node * left;
    Node * next;

    Node(int d = INT_MIN, Node * right = NULL, Node * left = NULL, Node *next = NULL)
    {
        data = d;
        this->right = right;
        this->left = left;
        this->next = next;
    }
};

class BinaryTree
{
public:
    Node * root;
    Node *prev;

    BinaryTree()
    {
//        cout<<"hello";
        root = NULL;
        prev = NULL;
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

    void inOrder(Node *temp)
    {
        if(!temp)
            return;

        inOrder(temp->left);
        cout<< temp->data<< "  ";
        inOrder(temp->right);

    }


    void inOrder_(Node *temp)
    {

        if(!temp)
            return;

        inOrder_(temp->left);

        if (prev != NULL)
                prev->next = temp;

        prev = temp;

        inOrder_(temp->right);
    }



};


int main()
{

    BinaryTree b;

    b.insertNode(10);
//    cout<< "hello";
    b.insertNode(8);
    b.insertNode(12);
    b.insertNode(3);

    cout<< "before \n";
    b.inOrder(b.root);

    cout<<"\nafter\n";
    b.inOrder_(b.root);

    Node *ptr = b.root->left->left;
    while(ptr)
    {
        cout << "Next of " << ptr->data << " is "
             << (ptr->next? ptr->next->data: -1)
             << endl;
        ptr = ptr->next;
    }

    return 0;
}

