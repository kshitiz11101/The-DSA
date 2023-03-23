class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        if(head1==NULL || head2==NULL){
            return NULL;
        }
        Node*temp=head2;
        set<int> s;
        while(temp!=NULL){
            s.insert(temp->data);
            temp=temp->next;
        }
        Node*intersection=new Node(0),*tracker=intersection;
        while(head1!=NULL){
            if(s.find(head1->data)!=s.end()){
                tracker->next=new Node(head1->data);
                tracker=tracker->next;
            }
            head1=head1->next;
        }
        return intersection->next;
    }
};