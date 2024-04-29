class Solution {
    public:
    Node* deleteK(Node *head,int K){
      //Your code here
      if(K==1)
      return NULL;
      int cnt=0;
      Node*prev=NULL;
      Node*curr=head;
      while(curr!=NULL){
          cnt++;
          if(cnt==K){
              prev->next=curr->next;
              cnt=0;
          }
          prev=curr;
          curr=curr->next;
      }
      return head;
    }
};
