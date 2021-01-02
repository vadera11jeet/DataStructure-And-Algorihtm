#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
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
        vector<int> v;

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

//        in order traversal of bst gives sorted array we can use this property to find number of swap for
        void print()
        {
            for(int i = 0; i<v.size(); i++)
                cout<<v[i]<< "  ";
        }

        int num_of_swap()
        {
            float count_ = 0;
            int i = 0;
            inOrderToStore(root);
            sort(v.begin(), v.end());
//            print();
            stack<Node *> s;
            Node * curr = root;

            while(!s.empty() || curr != NULL)
            {
                while(curr != NULL)
                {
                    s.push(curr);
                    curr = curr->left;
                }
                curr = s.top();
                s.pop();

                if(v[i] != curr->data)
                    count_++;
                i++;
                curr = curr->right;
            }
            return ceil(count_/2);

        }

    private:

        void inOrderToStore(Node * node)
        {
            if(!node)
                return;
            inOrderToStore(node->left);
            v.push_back(node->data);
            inOrderToStore(node->right);
        }
};

int main()
{
    BinaryTree b;

    b.insertNode(5);
    b.insertNode(6);
    b.insertNode(7);
    b.insertNode(8);
    b.insertNode(9);
    b.insertNode(10);
    b.insertNode(11);

    cout<< b.num_of_swap();

    return 0;
}
