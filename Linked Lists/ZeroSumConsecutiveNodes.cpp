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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode*front=new ListNode(0,head);
        
        ListNode*start=front;
        while(start!=NULL){
        int presum=0;
        ListNode*end=start->next;
        while(end!=NULL){
            presum+=end->val;
            if(presum==0){
                start->next=end->next;
            }
            end=end->next;
        }
            start=start->next;
            }
        return front->next;
       }
};
