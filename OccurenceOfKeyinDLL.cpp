class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        /*
        Node*temp=*head_ref;
        while(temp!=NULL){
            // occurence is at 1st node
            if(temp->data==x){
                if(temp->prev==NULL){
                *head_ref=temp->next;
                temp->prev=NULL;
                }
            
            // occurence is at last node
          else if(temp->next==NULL){
                temp->prev->next=NULL;
            }
            else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                }
            }
                temp=temp->next;
        }
        */
         Node*temp=*head_ref;
        while(temp!=NULL){
            // occurence is at 1st node
            if(temp->data==x){
                if(temp->prev==NULL){
                *head_ref=temp->next;
                temp->prev=NULL;
                }
            
            // occurence is at last node
          else if(temp->next==NULL){
                temp->prev->next=NULL;
            }
            // occurence is in middle
            else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                }
            }
                temp=temp->next;
        }
        
        
    }
};