#include<iostream>
using namespace std;

int search_(int arr[], int value, int size_)
{
    for(int i = 0; i<size_; i++)
    {
        if(arr[i] == value)
            return i;
    }
    return INT_MIN;
}

void postorder_from_inorder_and_preorder(int in[], int pre[], int n)
{
//    int in[] = { 4, 2, 5, 1, 3, 6 };
//    int pre[] = { 1, 2, 4, 5, 3, 6 };
//    in this method conversion is happen by using pre order traversal's first element we get root element here we 1 as root
//    by search this element in in_order traversal we get before the root element is left child of root node after root node all element is right sub tree

    int root = search_(in, pre[0], n);

    if(root!=0)
        postorder_from_inorder_and_preorder(in, pre+1, root); // here we can add 1 to base address and we get a next address of array element pointer arithmetic

    if(root != n-1)
        postorder_from_inorder_and_preorder(in+root+1, pre+ root + 1, n - root -1);

    cout<< pre[0] << " ";

}



int main()
{
    int in[] = { 4, 2, 5, 1, 3, 6 };
    int pre[] = { 1, 2, 4, 5, 3, 6 };

    postorder_from_inorder_and_preorder(in, pre, 6);

    return 0;
}
