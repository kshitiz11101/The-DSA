/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:
    
int findPosition(int in[],int element,int n){
        for(int i=0;i<n;i++){
            if(in[i]==element){
                return i;
            }
        }
        return -1;
    }
     Node*solve(int in[],int post[],int &index,int inorderStart,int inorderEnd,int n){
        // base case
        if(index<0 || inorderStart>inorderEnd){
            return NULL;
        }
        int element=post[index--];
        Node*root=new Node(element);
        int position=findPosition(in,element,n);
        // recursive calls[in case of postorder and inorder,we first built the right subtree]
         root->right=solve(in,post,index,position+1,inorderEnd,n);
        root->left=solve(in,post,index,inorderStart,position-1,n);
         return root;
        
    }
    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        int postOrderIndex=n-1;
        Node*ans =solve(in,post,postOrderIndex,0,n-1,n);
        return ans;
    }
};
