Node* reverseDLL(Node * head)
{
    //Your code here
    // Node*temp=head;
    // while(temp!=NULL){
    //     swap(temp->next,temp->prev);
    //     head=temp;
    //     temp=temp->prev;
    // }
    // return head;
    /*
    Node*temp=head;
    while(temp!=NULL){
        swap(temp->next,temp->prev);
        head=temp;
        temp=temp->prev;
    }
    return head;
    
    Node*temp=head;
    while(temp!=NULL){
        swap(temp->next,temp->prev);
        head=temp;
        temp=temp->prev;
    }
    return head;
    */
    Node*temp=head;
    while(temp!=NULL){
        swap(temp->next,temp->prev);
        head=temp;
        temp=temp->prev;
    }
    return head;
}