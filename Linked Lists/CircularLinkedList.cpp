#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // Constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << value << endl;
    }
};
void InsertNode(Node *&tail, int element, int d)
{
    // assuming that the element is present in the list
    // Empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non-empty list
        // assuming that the element is present in the list
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // element found->curr is representing element wala node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node *tail)
{
    Node *temp = tail;
    if (tail == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
void deleteNode(Node *&tail, int value)
{
    // empty list
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        // non-empty list
        // assuming that the value is present in the list
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        // for one node linked list
        if (curr == prev)
        {
            tail = NULL;
        }
        // >=2 node linked list
        if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}
bool circularList(Node *head)
{
    if (head == NULL)
    {
        return true;
    }
    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        return true;
    }
    return false;
}
int main()
{
    Node *tail = NULL;
    // Insertion in empty list
    InsertNode(tail, 5, 3);
    print(tail);
    /* InsertNode(tail, 3, 5);
     print(tail);
     InsertNode(tail, 5, 7);
     print(tail);
     InsertNode(tail, 7, 9);
     print(tail);
     InsertNode(tail, 5, 6);
     print(tail);
     InsertNode(tail, 3, 4);
     print(tail);

     */
    deleteNode(tail, 3);
    print(tail);
    if (circularList(tail))
    {
        cout << "Linked list is circular " << endl;
    }
    else
    {
        cout << "Linked list is not circular " << endl;
    }

    return 0;
}
int len = 0;
while (head != NULL)
{
    len++;
    head = head->next;
}
return len;
}
int getMiddle(Node *head)
{
    // Your code here
    int len = getLength(head);
    int ans = (len / 2);
    Node *temp = head;
    int cnt = 0;
    while (cnt < ans)
    {
        temp = temp->next;
        cnt++;
    }
    return temp->data;



    

    // Complete this method
    if (head == NULL)
    {
        return NULL;
    }
    //     Step-1: Reverse first k nodes
    node *next = NULL;
    node *curr = head;
    node *prev = NULL;
    int cnt = 0;
    while (curr != NULL && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    //     Step-2: Recursion dekhlega
    if (next != NULL)
    {
        head->next = reverse(next, k);
    }
    //     Step-3: Return head of reversed LL
    return prev;