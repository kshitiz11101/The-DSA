/*  Structure of a Binary Tree

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    void f(Node*root,unordered_map<int,int>&m,int hd){
        if(root==NULL)
        return;
        
        m[hd]++;
        f(root->left,m,hd-1);
        f(root->right,m,hd-1);
    }
    int getMaxWidth(Node* root) {

        // Your code here
       unordered_map<int,int>m;
       f(root,m,0);
       int ans=INT_MIN;
       for(auto i:m){
           ans=max(ans,i.second);
       }
       return ans;
    }
};
