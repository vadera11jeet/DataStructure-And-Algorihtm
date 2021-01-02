#include<iostream>
#include<queue>
using namespace std;

class LinkedListNode
{
public:
    int data;
    LinkedListNode * next;

    LinkedListNode(int data = INT_MIN, LinkedListNode * next = NULL)
    {
        this->data = data;
        this->next = next;
    }

};

class LinkedList
{
public:
    LinkedListNode *head, *tail;

    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insertNode(int value)
    {
        LinkedListNode *node = new LinkedListNode(value);

        if(!head)
        {
            head = node;
            tail = node;
            return ;
        }
        tail->next = node;
        tail = node;
    }

};


class Node
{
public :
    int data;
    Node *right , *left;

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
    LinkedList l;

    BinaryTree(LinkedList lj)
    {
        root = NULL;
        l = lj;
    }

    void createTree()
    {
        LinkedListNode *temp = l.head;
        if(!root)
        {
            root = new Node(temp->data);
            temp = temp->next;
        }
        queue<Node *> q;
        q.push(root);
        while(!q.empty() && temp != NULL)
        {
            Node *temp1 = q.front();
            q.pop();
            Node *withVal = new Node(temp->data);
            temp1->left = withVal;
            temp = temp->next;

            if(temp)
                withVal = new Node(temp->data);
            else
                break;

            temp1->right = withVal;
            temp = temp->next;
            q.push(temp1->left);
            q.push(temp1->right);

        }

    }

    void inOrder(Node *root)
    {
        if(!root)
            return ;
        inOrder(root->left);
        cout<<root->data<< "  ";
        inOrder(root->right);
    }


    void printLinkedList()
    {
        LinkedListNode  *temp = l.head;
        while(temp)
        {
            cout<<temp->data<< "  ";
            temp = temp->next;
        }
    }

};




int main()
{

    LinkedList l;

    l.insertNode(10);
    l.insertNode(12);
    l.insertNode(15);
    l.insertNode(25);
    l.insertNode(30);
    l.insertNode(36);

    BinaryTree b(l);

//    b.printLinkedList();

    b.createTree();

    b.inOrder(b.root);

    return 0;
}
