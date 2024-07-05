//Back-end complete function Template for C++
class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    
    int verticalWidth(Node* root) {
        // code here
        if(root==NULL){
            return 0;
        }
        
        unordered_map<int,int>m;
        queue<pair<Node*,int>>q;
        
        q.push({root,0});
        while(!q.empty()){
            Node*node=q.front().first;
            int line=q.front().second;
            q.pop();
            m[line]=1;
            if(node->left){
                q.push({node->left,line-1});
            }
            if(node->right){
                q.push({node->right,line+1});
            }
            
        }
        return m.size();
    }
};
