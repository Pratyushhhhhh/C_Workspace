#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to check for two nodes whose multiplication is less than the target
int checkMultiplication(struct Node* head, int target) {
    struct Node* first = head;
    struct Node* second;

    while (first != NULL) {
        second = first->next;
        while (second != NULL) {
            if (first->data * second->data < target)
                return 1; // Found a pair
            second = second->next;
        }
        first = first->next;
    }
    return 0; // No such pair exists
}

void insertEnd(struct Node** head, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
        return;
    }

    struct Node* p = *head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
}

void displayList(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* head = NULL;
    int choice, value, target;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert an element\n");
        printf("2. Display the linked list\n");
        printf("3. Check for two nodes with multiplication less than target\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {

                printf("Enter the value to insert: ");
                scanf("%d", &value);
              
                insertEnd(&head, value);
                break;
            }
            case 2:
                printf("Current Linked List:\n");
                displayList(head);
                break;
            case 3:
                printf("Enter the target value: ");
                scanf("%d", &target);
                if (checkMultiplication(head, target))
                    printf("Yes, there exist two nodes whose multiplication is less than %d.\n", target);
                else
                    printf("No, such nodes do not exist.\n");
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
