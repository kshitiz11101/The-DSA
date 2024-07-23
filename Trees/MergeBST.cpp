/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    
    // void mergeSort(int n,int m,vector<int>&ans1,vector<int>&ans2,vector<int>&ans){
    //     int i=0,j=0,k=0;
    //     while(i<n){
    //         ans[k++]=ans1[i++];
    //     }
    //      while(j<m){
    //         ans[k++]=ans1[j++];
    //     }
    // }
    
    void inorder(Node*root,vector<int>&a){
        if(root==NULL){
            return;
        }
        inorder(root->left,a);
        a.push_back(root->data);
        inorder(root->right,a);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
       
        vector<int>ans;
        inorder(root1,ans);
        inorder(root2,ans);
        sort(ans.begin(),ans.end());
        // int n=ans1.size(),m=ans2.size();
        // mergeSort(n,m,ans1,ans2,ans);
        
        // mergeBST()
        
        return ans;
        
    }
};
