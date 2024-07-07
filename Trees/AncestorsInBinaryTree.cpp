// User function template for C++

/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

class Solution {
  public:
    // Function should return all the ancestor of the target node
    vector<int>ans;
    int f(struct Node*root,int target){
       
       
       if(root==NULL)
       return 0;
       
       
        if(root->data==target){
            
            return 1;
        }
        int left=f(root->left,target);
        if(left){
            ans.push_back(root->data);
            return 1;
        }
        int right=f(root->right,target);
        if(right){
            ans.push_back(root->data);
            return 1;
        }
        return 0;
        
    }
    vector<int> Ancestors(struct Node *root, int target) {
        // Code here
        // vector<int>ans;
        
        // if(root==NULL || root->data==target){
        //     return {};
        // }
        ans.clear();
        f(root,target);
        return ans;
        
        
    }
};
