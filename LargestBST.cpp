class sol{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};
sol solve(Node*root,int &ans){
if(root==NULL){
    return {INT_MIN,INT_MAX,true,0};
    
}
sol left=solve(root->left,ans);
sol right=solve(root->right,ans);
sol curr;
curr.size=left.size+right.size+1;
curr.maxi=max(root->data,right.maxi);
curr.mini=min(root->data,left.mini);
if(left.isBST && right.isBST &&(root->data>left.maxi && root->data<right.mini)){
    curr.isBST=true;
}
else{
    curr.isBST=false;
}
if(curr.isBST){
    ans=max(ans,curr.size);
}
return curr;
}
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	int maxsize = 0;
        sol temp = solve(root, maxsize);
        return maxsize;
    }
};