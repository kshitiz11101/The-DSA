/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution
{
    public:
    // function should print the nodes at k distance from root
    void solve(struct Node*root,int k,vector<int> &ans){
    if(root==NULL){
      return;
  }
  if(k==0){
      ans.push_back(root->data);
  }
  else{
  solve(root->left,k-1,ans);
  solve(root->right,k-1,ans);
  
  }

}
    vector<int> Kdistance(struct Node *root, int k)
    {
      // Your code here
      vector<int>ans;
      solve(root,k,ans);
      return ans;
    }
};
