class Solution
{
    public:
    Node* getlastNode(Node*head){
        Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            
        }
        return temp;
    }
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        if(head==NULL ||head->next==NULL){
            return head;
        }
        Node*temp=head;
       Node*lastNode=getlastNode(temp);
       while(k){
           Node*forward=head->next;
           lastNode->next=head;
           lastNode=head;
           head=head->next;
           lastNode->next=NULL;
           --k;
       }
       return head;
    }
};