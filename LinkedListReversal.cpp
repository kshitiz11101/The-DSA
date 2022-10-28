struct Node
{
    int data;
    struct Node *next;
};
class Solution
{
    public:
struct Node* reverseList(struct Node *head)
    {
      
        struct Node*curr=head;
        struct Node*prev=NULL;
        struct Node*forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
};