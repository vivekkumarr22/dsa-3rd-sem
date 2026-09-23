#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* deleteBeginning(struct Node *head) {
    struct Node *temp, *last;

    if(head == NULL)
        return NULL;

    if(head->next == head) {
        free(head);
        return NULL;
    }

    last = head;

    while(last->next != head)
        last = last->next;

    temp = head;
    head = head->next;
    last->next = head;

    free(temp);

    return head;
}

struct Node* deleteEnd(struct Node *head) {
    struct Node *temp, *prev;

    if(head == NULL)
        return NULL;

    if(head->next == head) {
        free(head);
        return NULL;
    }

    temp = head;

    while(temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);

    return head;
}

void display(struct Node *head) {
    struct Node *temp;

    if(head == NULL) {
        printf("List is empty");
        return;
    }

    temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
}

int main() {
    struct Node *head, *n1, *n2, *n3;

    n1 = (struct Node*)malloc(sizeof(struct Node));
    n2 = (struct Node*)malloc(sizeof(struct Node));
    n3 = (struct Node*)malloc(sizeof(struct Node));

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = head;

    printf("Original list:\n");
    display(head);

    head = deleteBeginning(head);

    printf("\nAfter deleting first node:\n");
    display(head);

    head = deleteEnd(head);

    printf("\nAfter deleting last node:\n");
    display(head);

    return 0;
}
