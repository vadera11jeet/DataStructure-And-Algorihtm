#include<iostream>
#include<queue>
#include<stack>
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

class NodeDLL
{
public:
    int data;
    NodeDLL *prev, *next;

    NodeDLL(int data =  INT_MIN, NodeDLL * prev = NULL, NodeDLL *next = NULL)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }

};

class DoublyLinkedList
{
public:
    NodeDLL *head, *tail;

    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insertNode(int data)
    {

        if(!head)
        {
            NodeDLL * temp = new NodeDLL(data);
            head = temp;
            tail = temp;
            return;
        }

        NodeDLL *temp = new NodeDLL(data, tail);
        tail->next = temp;
        tail = tail->next;
    }

    void print()
    {
        NodeDLL *temp = head;
        while(temp)
        {
            cout<<temp->data << "  ";
            temp = temp->next;
        }
    }

};

class BinaryTree
{
    public:
        Node *root;
        DoublyLinkedList l;

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

        void treeToDLL()
        {
            stack<Node *> s;
            s.push(root);
            Node *curr = root->left;

            while(!s.empty() || curr !=NULL)
            {
                while(curr)
                {
                    s.push(curr);
                    curr = curr->left;
                }

                curr = s.top();
                s.pop();
                l.insertNode(curr->data);
                curr = curr->right;

            }

        }

};

int main()
{
    BinaryTree b;

    b.insertNode(10);
    b.insertNode(12);
    b.insertNode(15);
    b.insertNode(25);
    b.insertNode(30);
    b.insertNode(36);

    b.treeToDLL();

    b.l.print();


    return 0;
}

