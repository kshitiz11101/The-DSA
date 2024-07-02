
/*
The structure of linked list is the following
struct Node
{
    string data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    bool compute(Node* head) {
        // Your code goes here
        string ans="";
        
        Node*curr=head;
        while(curr!=NULL){
            ans+=curr->data;
            curr=curr->next;
        }
       int n=ans.size();
       for(int i=0;i<n/2;i++){
           if(ans[i]!=ans[n-i-1]){
               return false;
           }
       }
       return true;
        
            }
};
