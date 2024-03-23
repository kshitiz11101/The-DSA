/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode*reverse(ListNode*head){
    if(head==NULL){
        return NULL;
    }
    ListNode*prev=NULL;
    ListNode*forward=NULL;
    ListNode*curr=head;
    while(curr!=NULL){
        forward=curr->next;
       curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

void merge(ListNode*list1,ListNode*list2){
    while(list2){
        ListNode*nextNode=list1->next;
        list1->next=list2;
        list1=list2;
        list2=nextNode;
    }
}
    void reorderList(ListNode* head) {
         if(head==NULL || head->next==NULL){
        return;
    }
    ListNode*fast=head;
    ListNode*slow=head;
   ListNode*prev=head;
    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        fast=fast->next->next;
        slow=slow->next;
    }
   prev->next=NULL;
   ListNode*list1=head;
   ListNode*list2=reverse(slow);
   merge(list1,list2);
    }
};
