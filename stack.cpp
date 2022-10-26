#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
using namespace std;
class StackNode
{
    int data;
    StackNode *next;
    StackNode *head;
    // Constructor
    StackNode(int a)
    {
        this->data = a;
        this->next = NULL;
    }
    void push(int x)
    {
        StackNode *temp = new StackNode(x);
        temp->next = head;
        head = temp;
    }
    int pop(int x)
    {
        if (head == NULL){
            return -1;
        }

            int res = head->data;
            StackNode *temp = head;
            head = head->next;
            delete (temp);
            return res;

    }
};
*/
class ArrayStack
{
    int *arr;
    int size;
    int top;
    ArrayStack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
        void push(int element)
        {
            if (size - top > 1)
            {
                top++;
                arr[top] = element;
            }
            else
            {
                cout << "Stack OverFlow" << endl;
            }
        }
        void pop()
        {
            if (top >= 0)
            {
                top--;
            }
            else
            {
                cout << "Stack UnderFlow" << endl;
            }
        }
        int peak()
        {
            if (top >= 0)
            {
                return arr[top];
            }
            else
            {
                cout << "Stack is empty" << endl;
            }
        }
        bool isEmpty()
        {
            if (top == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    };

/*
class Stack
{
    // Properties
public:

        int *arr;
        int top;
        int size;

        // Behaviour
        Stack(int size)
        {
            this->size = size;
            arr = new int[size];
            top = -1;
        }
        void push(int element)
        {
            if (size - top > 1)
            {
                top++;
                arr[top] = element;
            }
            else
            {
                cout << "Stack OverFlow " << endl;
            }
        }
        void pop()
        {
            if (top >= 0)
            {
                top--;
            }
            else
            {
                cout << "Stack UnderFlow " << endl;
            }
        }
        int peak()
        {
            if (top >= 0)
                return arr[top];
            else
            {
                cout << "Stack is empty " << endl;
                return -1;
            }
        }
        bool isEmpty()
        {
            if (top == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        */

int main()

{
    ArrayStack st(5);
    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    st.push(44);
    st.pop(44);
    
    cout << st.peak() << endl;
    cout << st.peak() << endl;
    st.pop();
    cout << st.peak() << endl;
    st.pop();
    cout << st.peak() << endl;
    if (st.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty " << endl;
    }
    /*
    stack<int> s; // creation of stack
    s.push(2);    // insert operation
    s.push(5);    // insert operation
    // s.pop();      // delete operation
    s.pop();      // delete operation
    cout << "Printing top element " << s.top() << endl;
    if (s.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty " << endl;
    }
    cout << "Size of stack " << s.size() << endl;
    */

    return 0;
}