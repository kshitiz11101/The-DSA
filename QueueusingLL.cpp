#include <stdio.h> 
#include <stdlib.h>
struct node {
    int data;
    struct node * next;
};
struct node * front = NULL;
struct node * rear = NULL;
void push(int value) {
    struct node * ptr;
    ptr = (struct node * ) malloc(sizeof(struct node));
    ptr -> data = value;
    ptr -> next = NULL;
    if ((front == NULL) && (rear == NULL)) {
        front = rear = ptr;
    } else {
        rear -> next = ptr;
        rear = ptr;
    }
    printf("Node is Inserted\n");
}
int pop() {
    if (front == NULL) {
        printf("\nUnderflow\n");
        return -1;
    } else {
        struct node * temp = front;
        int temp_data = front -> data;
        front = front -> next;
        free(temp);
        return temp_data;
    }
}
void display() {
    struct node * temp;
    if ((front == NULL) && (rear == NULL)) {
        printf("\nQueue is Empty\n");
    } else {
        printf("The queue is \n");
        temp = front;
        while (temp) {
            printf("%d--->", temp -> data);
            temp = temp -> next;
        }
        printf("NULL\n");
    }
}
int main() {
    int choice, value;
    printf("\nImplementation of Queue using Linked List\n");
    while (choice) {
        printf("1.Push 2.Pop 3.Display 4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", & choice);
        switch (choice) {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", & value);
                push(value);
                break;
            case 2:
                printf("Popped element is :%d\n", pop());
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("\nWrong Choice\n");
        }
    }
    return 0;
}
