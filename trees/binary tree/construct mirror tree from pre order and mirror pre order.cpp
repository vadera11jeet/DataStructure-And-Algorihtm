#include<iostream>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node *right, *left;
    Node(int data = INT_MIN, Node * right = NULL, Node * left = NULL)
    {
        this->data = data;
        this->right = right;
        this->left = left;
    }
};

Node* constructBinaryTreeUtil(int pre[], int preM[],
                    int &preIndex, int l,int h,int size)
{

    if (preIndex >= size || l > h)
        return NULL;

    Node* root = new Node(pre[preIndex]);
        ++(preIndex);

    if (l == h)
        return root;

    int i;
    for (i = l; i <= h; ++i)
        if (pre[preIndex] == preM[i])
            break;

    if (i <= h)
    {
        root->left = constructBinaryTreeUtil (pre, preM,
                                    preIndex, i, h, size);
        root->right = constructBinaryTreeUtil (pre, preM,
                                 preIndex, l+1, i-1, size);
    }


    return root;
}

void printInorder(Node * root)
{
    if(!root)
        return ;
    printInorder(root->left);
    cout<<root->data<< "  ";
    printInorder(root->right);
}

void constructBinaryTree(Node* root,int pre[],
                        int preMirror[], int size)
{
    int preIndex = 0;
    int preMIndex = 0;

    root =  constructBinaryTreeUtil(pre,preMirror,
                            preIndex,0,size-1,size);

    printInorder(root);
}

int main()
{
    int preOrder[] = {1,2,4,5,3,6,7};
    int preOrderMirror[] = {1,3,7,6,2,5,4};

    int size_ = sizeof(preOrder)/sizeof(preOrder[0]);

    Node* root = new Node;

    constructBinaryTree(root,preOrder,preOrderMirror,size_);
    return 0;
}
