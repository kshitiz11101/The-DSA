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
Node *buildTree(Node *root)
{
    cout << "Enter the data for node " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();
        if (temp == NULL)
        { // purana level complete traverse ho chuka h
            cout << endl;
            if (!q.empty())
            { // queue still has some nodes
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
/*
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
*/
void InOrder(Node*root){
    if(root==NULL){
        return;
    }
    stack<Node*> s;
    Node*curr=root;
    while(curr!=NULL || !s.empty()){
        while(curr!=NULL){
        s.push(curr);
        curr=curr->left;
            }
            while (!s.empty())
            {
                 curr=s.top();
            s.pop();
            cout<<curr->data<<" ";
            }
            curr=curr->right;
            
           
    }

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
void buildFromLevelOrder(Node *&root)
{
    queue<Node *> q;
    cout << "Enter data for root " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << "Enter left node for : " << temp->data << endl;
        int LeftData;
        cin >> LeftData;
        if (LeftData != -1)
        {
            temp->left = new Node(LeftData);
            q.push(temp->left);
        }
        cout << "Enter Right node for : " << temp->data << endl;
        int RightData;
        cin >> RightData;
        if (RightData != -1)
        {
            temp->right = new Node(RightData);
            q.push(temp->right);
        }
    }
}
int main()
{
    Node *root = NULL;
    // buildFromLevelOrder(root);
    // levelOrderTraversal(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    
    // creating a tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // level order
    cout << "Printing the level order traversal output " << endl;
    levelOrderTraversal(root);

    cout << "InOrder traversal is :" << endl;
    InOrder(root);
    /*
    cout << endl;
    cout << "PreOrder traversal is :" << endl;
    PreOrder(root);
    cout << endl;
    cout << "PostOrder traversal is :" << endl;
    PostOrder(root);
    */

    return 0;
}










