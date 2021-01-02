#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int data = INT_MIN, Node *right = NULL, Node *left = NULL)
    {
        this->data = data;
        this->right = right;
        this->left = left;
    }
};

vector<int> getKey(vector<int> level, vector<int> pre, int start_, int end_, int size_)
{
    vector <int> vec ;
    for(int i=0; i<size_; i++)
    {
        for(int j = start_ ;j < end_; j++)
        {
            if(level[i] == pre[j])
            {
                vec.push_back(level[i]);
                break;
            }
        }
    }
    return vec;
}

/* Function to find index of value in arr[start...end] */
int search(int arr[], int strt, int end, int value)
{
    for (int i = strt; i <= end; i++)
        if (arr[i] == value)
            return i;
    return -1;
}

int *extrackKeys(int in[], int level[], int m, int n)
{
    int *newlevel = new int[m], j = 0;
    for (int i = 0; i < n; i++)
        if (search(in, 0, m-1, level[i]) != -1)
            newlevel[j] = level[i], j++;
    return newlevel;
}


Node* buildTree(int in[], int level[], int inStrt, int inEnd, int n)
{
    if (inStrt > inEnd)
        return NULL;

    Node *root = new Node(level[0]);

    if (inStrt == inEnd)
        return root;

    int inIndex = search(in, inStrt, inEnd, root->data);

    int *llevel  = extrackKeys(in, level, inIndex, n);

    int *rlevel  = extrackKeys(in + inIndex + 1, level, n-inIndex-1, n);

    root->left = buildTree(in, llevel, inStrt, inIndex-1, inIndex-inStrt);
    root->right = buildTree(in, rlevel, inIndex+1, inEnd, inEnd-inIndex);

    delete [] llevel;
    delete [] rlevel;

    return root;
}
void preOrder(Node *root)
{
    if(!root)
        return;

    preOrder(root->left );
    cout<<root->data<< "  ";
    preOrder(root->right);

}

int main()
{

    int in[]    = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(in)/sizeof(in[0]);
    Node *root = buildTree(in, level, 0, n - 1, n);

    return 0;
}
