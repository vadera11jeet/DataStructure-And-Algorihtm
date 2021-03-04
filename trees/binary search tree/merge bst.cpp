#include<bits/stdc++.h>
using namespace std;
// this code is inefficient approach.
// here in order traversal is applied on both BST and then create balanced BST
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


class BinarySearchTree
{
public:
    Node *root;
    vector<int> v;

    BinarySearchTree()
    {
        root = NULL;
    }


    void insertNode(int value)
    {
        Node *newNode = new Node(value);
        if(!root)
            root = newNode;
        else
        {
            Node *temp = root;
            Node *par;
            while(temp)
            {
                par = temp;
                if(temp->data >= value)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }

            if(par->data >= value)
                par->left = newNode;
            else
                par->right = newNode;

        }
    }

    void inorder(Node *root)
    {
//      if you peform in order traversal on BST we get sorted value
        if(!root)
            return;
        inorder(root->left);
//        cout<<root->data<<"  ";
        v.push_back(root->data);
        inorder(root->right);
    }

};

Node *mergeTwoBinaryTree(vector<int> v, int start, int end_)
{
    if(start > end_)
        return NULL;


    int mid = (start + end_) / 2;

    Node *root = new Node(v[mid]);

    root->left = mergeTwoBinaryTree(v, start, mid-1);
    root->right = mergeTwoBinaryTree(v, mid+1, end_);

    return root;
}

void inorder(Node *root)
{
//      if you peform in order traversal on BST we get sorted value
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<"  ";
//    v.push_back(root->data);
    inorder(root->right);
}

void inorder_(Node *root, vector<int> & ans)
{
    if(!root)
        return;
    inorder_(root->left, ans);
    ans.push_back(root->data);
    inorder_(root->right, ans);
}
// this approach take O(m + n) time complexity and O(H1 + H2) auxiliary complexity
vector<int> merge(Node *root1, Node *root2)
{
   //Your code here
       vector<int> ans;
    stack<Node *> s1, s2;

    Node * curr1 = root1;
    Node * curr2 = root2;

    while(!s1.empty() || curr1 != NULL || !s2.empty() || curr2 != NULL)
    {
        if(curr1 != NULL || curr2 != NULL)
        {
            if(curr1 != NULL)
            {
                s1.push(curr1);
                curr1 = curr1->left;
            }
            if(curr2 != NULL)
            {
                s2.push(curr2);
                curr2 = curr2->left;
            }
        }

        else
        {
            if(s1.empty())
            {
                while(!s2.empty())
                {
                    curr2 = s2.top();
                    curr2->left = NULL;
                    inorder_(curr2, ans);
                    s2.pop();
                }
                return ans;
            }

            if(s2.empty())
            {
                while(!s1.empty())
                {
                    curr1 = s1.top();
                    curr1->left = NULL;
                    inorder_(curr1, ans);
                    s1.pop();
                }
                return ans;
            }

            curr1 = s1.top();
            curr2 = s2.top();

            if(curr1->data > curr2->data)
            {
               ans.push_back(curr2->data);
               s2.pop();
               curr2 = curr2->right;
               curr1 = NULL;
            }

            else
            {
                ans.push_back(curr1->data);
                s1.pop();
                curr1 = curr1->right;
                curr2 = NULL;
            }
        }
    }

    return ans;
}

int main()
{
    BinarySearchTree b1, b2;

    b1.insertNode(3);
    b1.insertNode(5);
    b1.insertNode(1);

    b1.inorder(b1.root);

    b2.insertNode(4);
    b2.insertNode(6);
    b2.insertNode(2);

    b2.inorder(b2.root);

//  this is the code for merging 2 vectors
    vector<int> v;
//    merge(b1.v.begin(), b1.v.end() ,b2.v.begin(), b2.v.end(), v.begin());
//
//    Node *root = mergeTwoBinaryTree(v, 0, v.size()-1);
//
//    inorder(root);

    v = merge(b1.root, b2.root);
    for(int x : v)
        cout<<x<< " ";

    return 0;
}
