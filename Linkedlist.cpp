#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // Destructor
    ~Node()
    {
        int value = this->data;
        // memory free

        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for mode with data " << value << endl;
    }
};
void InsertAtHead(Node *&head, int d)
{
    // New node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void InsertAtPosition(Node *&head, int position, int d)
{
    // Insert at start
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // Creating a node for d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}
void DeleteNode(int position, Node *&head)
{
    // Deleting first node:
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free start node
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node:
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            curr->next = NULL;
            cnt++;
        }
        prev->next = curr->next;
        delete curr;
    }
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *floydDetectLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (slow!=NULL&&fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;

        }
        slow=slow->next;
        if (slow==fast)
        {
            return true;
        }
        return false;
        
    }

    
}
Node *startingNodeLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *intersection = detectLoop(head);
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}
 void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(head==NULL){
            return ;
        }
        Node*startingNode=getStartingNodeLoop(head);
        Node*temp=startingNode;
        while(temp->next!=startingNode){
            temp=temp->next;
        }
        temp->next=NULL;
        
    }
int main()
{
    // Create a new node
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    // head pointer to node1
    Node *head = node1;
    Node *tail = node1;
    // print(head);
    InsertAtHead(head, 12);
    // print(head);
    InsertAtHead(head, 15);

    InsertAtTail(tail, 10);
    // print(head);
    InsertAtTail(tail, 12);
    // print(head);
    tail->next = head->next;

    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    if (detectLoop(head))
    {
        cout << "Loop is present " << endl;
    }
    else
    {
        cout << "Loop is absent " << endl;
    }

    // InsertAtTail(tail, 15);
    // print(head);
    // InsertAtPosition(head, 4, 22);
    // print(head);
    // DeleteNode(3, head);
    // print(head);
    return 0;
}
 if(head==NULL){
            return false;
        }
        Node*slow=head;
        Node*fast=head;
        while(fast!=NULL&&slow!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
    if (headA == NULL && headB == NULL) {
	return 1;
} else if (headA == NULL || headB == NULL) {
	return 0;
}

if (headA->data == headB->data) {
	return CompareLists(headA->next, headB->next);
} else {
	return 0;
}


// Add 2 numbers in form of LL
 Node*reverse(Node*head){
        Node*curr=head;
        Node*prev=NULL;
        Node*next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void insertAtTail(struct Node*&head, struct Node*&tail,int val){
        Node*temp=new Node(val);
        // Empty list
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        
        
    }
     struct Node* add(struct Node* first, struct Node* second){
         int carry=0;
         
         Node*ansHead=NULL;
         Node*ansTail=NULL;
         while(first!=NULL ||second!=NULL||carry!=0){
             int val1=0;
             if(first!=NULL){
                 val1=first->data;
             }
             int val2=0;
             if(second!=NULL){
                 val2=second->data;
             }
             
             int sum=carry+val1+val2;
             int digit=sum%10;
            // Create node and add in answer LL
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
            if(first!=NULL)
            first=first->next;
            if(second!=NULL)
            second=second->next;
         }
        
         return ansHead;
     }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        // Step-1:reverse input linked list:
        first=reverse(first);
        second=reverse(second);
        // Step-2:Add 2 LL
        Node*ans=add(first,second);
        // Step-3:reverse ans wali LL
        ans=reverse(ans);
        
        
    return ans;
    }
    void insertAtTail(Node*&tail,Node*&curr){
        tail->next=curr;
        tail=curr;
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node*zeroHead=new Node(-1);
        Node*zeroTail=zeroHead;
        Node*oneHead=new Node(-1);
         Node*oneTail=oneHead;
        Node*twoHead=new Node(-1);
         Node*twoTail=twoHead;
         Node*curr=head;
        //  Create a separate list for 0s 1s and 2s
    while(curr!=NULL){
        int value=curr->data;
        if(value==0){
            insertAtTail(zeroTail,curr);
            
        }
        else if(value==1){
            insertAtTail(oneTail,curr);
        }
        else if(value==2){
            insertAtTail(twoTail,curr);
            
        }
        curr=curr->next;
    }    
    // Merge 3 sublist
    if(oneHead->next!=NULL){ // 1's list is non-empty
        zeroTail->next=oneHead->next;
    }
    else{
        // 1's list is empty
         zeroTail->next=twoHead->next;
    }
    oneTail->next=twoHead->next;
    twoTail->next=NULL;
    // Setup head
    head=zeroHead->next;
    // Delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
    }





    // Merge sort in two sorted LL
    Node<int>* solve(Node<int>* first, Node<int>* second){
         if(first->next==NULL){
         first->next=second;
         return first;
}
    Node<int>*curr1=first;
    Node<int>*next1=curr1->next;
    Node<int>*curr2=second;
    Node<int>*next2=curr2->next;
    while(next1!=NULL &&curr2!=NULL){
        if((curr2->data>=curr1->data)&&(curr2->data<=next1->data)){
//             add node in between first LL
            curr1->next=curr2;
            next2=curr2->next; 
            curr2->next=next1;
//             Update pointers
            curr1=curr2;
            curr2=next2;
}
           else{
//                curr1 and next1 ko aage bhadana h
               curr1=next1;
               next1=next1->next;
               if(next1==NULL){
                   curr1->next=curr2;
                   return first;
}           
}

           return first;
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second){

//     Write your code here.
    if(first==NULL){
return second;
    }
    if(second==NULL){
return first;
    }
    if(first->data<=second->data){
      return solve(first,second);
    }
    else{
        return solve(second,first);
    } 
}







// Merge sort in LL
 private:
    Node*merge( Node*left,Node*right){
    if(left==NULL){
return right;
    }
    if(right==NULL){
     return left;
    }
    Node*ans=new Node(-1);
    Node*temp=ans;
//     merge two sorted LL
    while(left!=NULL&&right!=NULL){
                if(left->data < right->data) {
                    temp->next=left;
                    temp=left;
                    left=left->next;
}
        else{
            temp->next=right;
            temp=right;
            right=right->next;
}
    }
    while(left!=NULL){
        temp->next=left;
        temp=left;
        left=left->next;
    }
     while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
    }
    ans=ans->next;
    return ans;
    }
Node*findMid(Node*head){
    Node*slow=head;
    Node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;3
}
    return slow;
}
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
         if(head==NULL || head->next==NULL){
             return head;
    }
//     break LL into two halves,after finding mid
    Node*mid=findMid(head);
    Node*left=head;
    Node*right=mid->next;
    mid->next=NULL;
//     recursove calls to solve both halves
    left=mergeSort(left);
    right=mergeSort(right);
//     merge both left and right halves
    Node*result=merge(left,right);
    return result;
    
    }


    // Delete middle Node
    Node* deleteMid(Node* head)
{
    // Your Code Here
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    if(slow->next==NULL){
        head->next=NULL;
        return head;
    }
    slow->data=slow->next->data;
    slow->next=slow->next->next;
    return head;
}
}


// duplicates from unsorted LL
  Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     if(head==NULL){
         return NULL;
     }
     map<int,int> visited;
     Node*curr=head;
     visited[curr->data]=1;
     Node*prev=head;
     curr=curr->next;
     while(curr!=NULL){
         if(visited[curr->data]){
             prev->next=curr->next;
             delete curr;
         }
         else{
             visited[curr->data]=1;
             prev=prev->next;
         }
         curr=curr->next;
         
     }
     return head;
    }