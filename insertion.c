#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* insertEnd(struct Node *head, int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    temp = head;

    while(temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;

    return head;
}

struct Node* insertBeginning(struct Node *head, int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    temp = head;

    while(temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;

    return newNode;
}

void display(struct Node *head) {
    struct Node *temp;

    if(head == NULL)
        return;

    temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
}

int main() {
    struct Node *head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    printf("Original list:\n");
    display(head);

    head = insertBeginning(head, 5);

    printf("\nAfter insertion at beginning:\n");
    display(head);

    head = insertEnd(head, 40);

    printf("\nAfter insertion at end:\n");
    display(head);

    return 0;
}
