#include <iostream>
using namespace std;

    class Solution
{
public:
   
    Node *solve(int pre[], int mini, int maxi, int &index, int n)
    {
        if (index >= n)
        {
            return NULL;
        }
        // check for out of range
        if (pre[index] < mini || pre[index] > maxi)
        {
            return NULL;
        }
        // we are in range now
        // recursive calls
        Node *root = newNode(pre[index++]);
        root->left = solve(pre, mini, root->data, index, n);
        root->right = solve(pre, root->data, maxi, index, n);
        return root;
    }
    // Function that constructs BST from its preorder traversal.
    Node *post_order(int pre[], int size)
    {
        // code here
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int index = 0;
        return solve(pre, mini, maxi, index, size);
    }
};