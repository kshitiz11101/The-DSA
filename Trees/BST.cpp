#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *insertIntoBST(Node *&root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        // right part mei insert
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}
void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL) // ek level traverse hogya
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void InOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}
void PreOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void PostOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}
Node
Node *DeleteFromBST(Node *root, int val)
{
    // base case
    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {
        // 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        

        // 1 child
        // left child
        if(root->left!=NULL && root->right==NULL){
            Node*temp=root->left;
            delete root;
            return temp;
        }
// right child
 if(root->left==NULL && root->right!=NULL){
            Node*temp=root->right;
            delete root;
            return temp;
        }
        // 2 child
        if(root->left!=NULL && root->right!=NULL){
            int min=minval(root->right)->data;
            root->data=min;
            root->right=DeleteFromBST(root->right,min);
            return root; 
        }
    }
    else if (root->data > val)
    {
        root->left = DeleteFromBST(root->left, val);
        return root;
    }
    else
    {
        root->right = DeleteFromBST(root->right, val);
    }
}
int main()
{
    // 10 8 21 7 27 5 4 3 -1
    Node *root = NULL;
    cout << "Enter data to create BST" << endl;
    takeInput(root);
    cout << "Level order traversal of BST is :" << endl;
    LevelOrderTraversal(root);
    cout << "Printing inorder :" << endl;
    InOrder(root);
    cout << endl
         << "Printing Preorder :" << endl;
    PreOrder(root);
    cout << endl
         << "Printing Postorder :" << endl;
    PostOrder(root);
    return 0;
}