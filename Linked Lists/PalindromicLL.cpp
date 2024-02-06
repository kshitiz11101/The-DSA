class Solution {
public:
  ListNode*getMid( ListNode*head){
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            
        }
        return slow;
    }
    ListNode*reverse(ListNode*head){
         ListNode*prev=NULL;
         ListNode*curr=head;
         ListNode*forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
         if(head->next==NULL){
            return true;
            }
             ListNode*middle=getMid(head);
             ListNode*temp=middle->next;
            middle->next=reverse(temp);
             ListNode*head1=head;
            ListNode*head2=middle->next;
            while(head2!=NULL){
                if(head1->val!=head2->val){
                    return false;
                }
                head1=head1->next;
                head2=head2->next;
            }
            temp=middle->next;
            middle->next=reverse(temp);
            return true;
    }
};