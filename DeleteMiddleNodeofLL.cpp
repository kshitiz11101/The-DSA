class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            head=NULL;
            return NULL;
        }
         ListNode*slow=head;
    ListNode*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    if(slow->next==NULL){
        head->next=NULL;
        return head;
    }
    slow->val=slow->next->val;
    slow->next=slow->next->next;
    return head;
    }
};