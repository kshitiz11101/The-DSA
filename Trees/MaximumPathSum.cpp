class Solution {
public:
 int solve(TreeNode*root,int &ans){
        if(root==NULL){
            return 0;
        }
        int left=solve(root->left,ans);
        int right=solve(root->right,ans);
        ans=max({ans,root->val+left+right,root->val,root->val+left,root->val+right});
        return max({root->val, root->val + left, root->val + right});
    }
    int maxPathSum(TreeNode* root) {
         int ans=INT_MIN;
        int x=solve(root,ans);
        return ans;
    }
};