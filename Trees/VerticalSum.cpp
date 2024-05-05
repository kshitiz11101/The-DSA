/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
class Solution{
  public:
  void solve(Node*root,map<int,int>&m,int level){
      if(root==NULL)
      return;
      
      m[level]+=root->data;
      solve(root->left,m,level-1);
      solve(root->right,m,level+1);
  }
    vector <int> verticalSum(Node *root) {
        // add code here.
        vector<int>ans;
        map<int,int>m;
        solve(root,m,0);
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};
