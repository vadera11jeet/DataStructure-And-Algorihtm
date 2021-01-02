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
    int find_HeightParent(Node *curr,int &parent,int value,int height)
    {
        if(!curr)
            return 0;
        if(curr->data==value)
            return height;

        parent = curr->data;
        int left = find_HeightParent(curr->left,parent,value,height+1);
        if(left)
            return left;
        parent = curr->data;
        int right = find_HeightParent(curr->right,parent,value,height+1);
        return right;
    }

    bool isCousins(Node* root, int x, int y) {

        if(root->data==x || root->data==y)
            return false;

        int parent=-1;
        int xHeight = find_HeightParent(root,parent,x,0);

        int yParent=-1;
        int yHeight = find_HeightParent(root,yParent,y,0);

        if(parent!=yParent && xHeight==yHeight)
            return true;
        return false;
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
    b.insertNode(8);
    b.insertNode(9);
    b.insertNode(10);
    b.insertNode(11);
    b.insertNode(12);
    b.insertNode(13);
    b.insertNode(14);
    b.insertNode(15);
//    b.insertNode(14);

    cout<< b.isCousins(b.root, 7, 15);

    return 0;
}
