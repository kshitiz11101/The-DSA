#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
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
// Traversing a linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// gives length of linked list
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        cout << temp->data << " ";
        temp = temp->next;
    }
    return len;
}
void insertAtHead(Node *&tail, Node *&head, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node *&tail, Node *&head, int d)
{
    if (tail == NULL)

    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    // insert at start
    if (position == 1)
    {
        insertAtHead(tail, head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // Inserting at last position
    if (temp->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }

    // Creating a node for d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
void DeleteNode(int position, Node *&head)
{
    // Deleting first node:
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;

        head = temp->next;
        temp->next = NULL;
        // memory free start node
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
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        //  memory free start node
        delete curr;
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    cout << getLength(head) << endl;
    insertAtHead(tail, head, 11);
    print(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    insertAtHead(tail, head, 13);
    print(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    insertAtTail(tail, head, 15);
    print(head);
    insertAtPosition(tail, head, 5, 100);
    print(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    insertAtPosition(tail, head, 3, 103);
    print(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    DeleteNode(3, head);
    print(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    return 0;
}