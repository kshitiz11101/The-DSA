#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
    ~node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << value << endl;
    }
};
void printDoublyLL(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void insertionAtFront(node *&head, int d)
{
    if (head == NULL)
    {
        node *temp = new node(d);
        head = temp;
        temp->next = NULL;
    }
    else
    {
        node *temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertionAtEnd(node *&head, int d)
{
    node *temp = new node(d);
    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
    }
    temp->next = NULL;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = temp;
    temp->prev = head;
    head = temp;
}
void insertionAtPosition(node *&head, int d, int pos)
{
    if (pos == 1)
    {
        insertionAtFront(head, d);
    }
    node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next = NULL)
    {
        insertionAtEnd(head, d);
    }
    node *nodeToInsert = new node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
void deleteNode(node*&head,int pos){
if(pos==1){
    node*temp=head;
    temp->next->prev=NULL;
    head=temp->next;
    temp->next=NULL;
    delete temp;
}
node*curr=head;
node*prev=NULL;
int cnt=1;
while (cnt<pos)
{
    prev = curr;
  curr = curr->next;
  curr->next = NULL;
       cnt++;
}
curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        //  memory free start node
        delete curr;

}
int main()
{
node*node1=new node(10);
node*head=node1;
  insertionAtFront(head,13);
  insertionAtFront(head,14);
  insertionAtEnd(head,15);
  printDoublyLL(head);
  insertionAtPosition(head,19,1);
  printDoublyLL(head);
   deleteNode(head,2);
  printDoublyLL(head);


    return 0;
}