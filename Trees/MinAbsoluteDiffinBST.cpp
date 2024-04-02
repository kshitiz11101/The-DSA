class Solution
{
    public:
    void inorder(Node*root,vector<int>&v){
        if(root==NULL)
        return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    int absolute_diff(Node *root)
    {
        //Your code here
        int mini=INT_MAX;
        vector<int>v;
        inorder(root,v);
        int n=v.size();
        for(int i=0;i<n-1;i++){
            if(v[i+1]-v[i]<mini){
                mini=v[i+1]-v[i];
            }
        }
        return mini;
    }
};
