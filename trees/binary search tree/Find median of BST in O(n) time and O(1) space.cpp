#include<bits/stdc++.h>
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

class BinarySearchTree
{
public:
    Node *root;
    int countOfNode;


    BinarySearchTree()
    {
        root = NULL;
        countOfNode= 0;
    }

    void insertNode(int value)
    {
        Node * newNode = new Node(value);

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
                    temp = temp->left;
                else
                    temp = temp->right;
            }

            if(par->data >= value)
                par->left = newNode;
            else
                par->right = newNode;
        }
        countOfNode++;
    }

    int getMidian()
    {

        if(!root)
            return INT_MIN;

        if(!root->left && ! root->right)
            return root->data;

        Node *curr = root, *prev;
        int k = 0;
        int ans;
        if(countOfNode % 2 != 0)
        {
            countOfNode = (countOfNode/2) + 1;
            while(curr)
            {
                if(!curr->left)
                {
                    k++;
                    if(k == countOfNode)
                    {
                        ans = curr->data;

                    }
                    curr = curr->right;
                }
                else
                {
                    prev = curr->left;

                    while(prev->right && prev->right != curr)
                        prev = prev->right;

                    if(!prev->right)
                    {
                        prev->right = curr;
                        curr = curr->left;
                    }
                    else
                    {
                        k++;
                        prev->right = NULL;
                        if(k == countOfNode)
                        {
                            ans = curr->data;
                        }
                        curr = curr->right;
                    }

                }
            }
            return ans;
        }
        else
        {
            countOfNode = (countOfNode / 2) + 1;
            int prevs, fps;
            bool flag = false;

            while(curr)
            {
                if(!curr->left)
                {
                    k++;
                    if(k == countOfNode)
                    {
                        fps = prevs;
                        ans = curr->data;
                    }
                    else
                    {
                        prevs = curr->data;
                    }
                    curr = curr->right;
                }
                else
                {
                    Node *prev = curr->left;

                    while(prev->right && prev->right != curr)
                        prev = prev->right;

                    if(!prev->right)
                    {
                        prev->right = curr;
                        curr = curr->left;
                    }
                    else
                    {
                        k++;
                        prev->right = NULL;
                        if(k == countOfNode)
                        {
                            fps = prevs;
                            ans = curr->data;
                        }
                        else
                        {
                            prevs = curr->data;
                        }

                        curr = curr->right;

                    }


                }
            }


            return (fps + ans)/2;

        }

    }



};


int main()
{
    BinarySearchTree b;

    b.insertNode(6);
    b.insertNode(3);
    b.insertNode(8);
    b.insertNode(1);
    b.insertNode(4);
    b.insertNode(7);
    b.insertNode(9);

//    cout<<b.countOfNode<<endl;


    cout<<b.getMidian();

    return 0;
}
