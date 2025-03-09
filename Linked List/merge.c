#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}sn;

sn *createnode(int value) {
    sn* newnode = (sn*)malloc(sizeof(sn));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void insertAtEnd(sn **head, int data) {
    sn *newNode = createnode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        sn *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

sn* merge(sn* head1, sn* head2) {
    sn* dummy = createnode(-1); // Dummy node
    sn* temp = dummy;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            temp->next = head1;
            head1 = head1->next;
        } else {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    // Append the remaining elements
    if (head1 != NULL) {
        temp->next = head1;
    } else {
        temp->next = head2;
    }

    sn* mergedHead = dummy->next;
    free(dummy); // Free the dummy node
    return mergedHead;
}

void displayList(sn* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    sn *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    sn* head1 = NULL;
    sn* head2 = NULL;

    insertAtEnd(&head1, 2);
    insertAtEnd(&head1, 4);
    insertAtEnd(&head1, 8);
    insertAtEnd(&head1, 10);

    insertAtEnd(&head2, 1);
    insertAtEnd(&head2, 3);
    insertAtEnd(&head2, 6);
    insertAtEnd(&head2, 11);
    insertAtEnd(&head2, 14);

    displayList(head1);
    printf("\n");
    displayList(head2);
    printf("\n");

    sn* head3 = merge(head1, head2);
    displayList(head3);

    return 0;
}
