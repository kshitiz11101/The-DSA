class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
        return head;
        while(head!=NULL && head->val==val){
            head=head->next;
        }
       
        ListNode*prev=NULL;
        ListNode*curr=head;
        while(curr!=NULL){
            if(curr->val==val){
                prev->next=curr->next;
            curr=curr->next;
            }
            else{
            prev=curr;
            curr=curr->next;
            }
        }
        return head;
    }
};
