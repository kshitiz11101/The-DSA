/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */


class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    void solve(Node*root,vector<int>&ans){
        if(root==NULL)
        return ;
        solve(root->left,ans);
        ans.push_back(root->data);
        solve(root->right,ans);
    }
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       Node*root=new Node(A.back());
       Node*temp=root;
       int n=A.size();
       for(int i=n-2;i>=0;i--){
           Node*node=new Node(A[i]);
           temp->left=node;
           temp=node;
       }
       return root;
    }

};
