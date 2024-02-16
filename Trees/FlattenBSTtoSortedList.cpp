class Solution
{
public:
Node*head,*root1;
bool flag=true;
void fun(int val){
    Node*t=new Node(val);
    if(flag){
        root1=t;
        head=root1;
        flag=false;
    }
    else{
        root1->right=t;
        root1=root1->right;
    }
}
void inorder(Node*root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    fun(root->data);
    inorder(root->right);
}
    Node *flattenBST(Node *root)
    {
        // code here
       inorder(root);
       return head;
    }
};
