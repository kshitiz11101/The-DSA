/*

Definition for Binary Tree Node
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
  void solve(Node*root,vector<vector<int>>&ans,vector<int>list){
      if(root==NULL)
      return ;
      
          list.push_back(root->data);
      if(root->left==NULL && root->right==NULL){
          ans.push_back(list);
          list.pop_back();
          return;
      }
      solve(root->left,ans,list);
      solve(root->right,ans,list);
  }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>ans;
        vector<int>list;
           if(root==NULL){
            return ans;
        }
        solve(root,ans,list);
        return ans;
    }
};
