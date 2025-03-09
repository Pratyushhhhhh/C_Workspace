#include <stdio.h>
#include <stdlib.h>
// Definition of the Node structure
struct Node
{
    int data;
    struct Node *next;
};
// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Function to insert a node at the end of the list
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
// Function to display the linked list
void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Function to find and delete the node with the second minimum data
void deleteSecondMinimum(struct Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        printf("List is too short to find the second minimum.\n");
        return;
    }

    struct Node *firstMin = NULL, *secondMin = NULL;
    struct Node *prevFirstMin = NULL, *prevSecondMin = NULL;
    struct Node *current = *head, *prev = NULL;

    // Find the first minimum and second minimum nodes
    while (current != NULL)
    {
        if (firstMin == NULL || current->data < firstMin->data)
        {
            secondMin = firstMin;
            prevSecondMin = prevFirstMin;
            firstMin = current;
            prevFirstMin = prev;
        }
        else if ((secondMin == NULL || current->data < secondMin->data) && current->data > firstMin->data)
        {
            secondMin = current;
            prevSecondMin = prev;
        }
        prev = current;
        current = current->next;
    }

    if (secondMin == NULL)
    {
        printf("No second minimum exists in the list.\n");
        return;
    }

    // Delete the second minimum node
    if (prevSecondMin == NULL)
    {
        // If secondMin is the head
        *head = secondMin->next;
    }
    else
    {
        prevSecondMin->next = secondMin->next;
    }
    free(secondMin);
    printf("The node with the second minimum data has been deleted.\n");
}

// Function to delete the entire linked list
void deleteList(struct Node **head)
{
    struct Node *current = *head;
    struct Node *nextNode;
    while (current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
    printf("The list has been deleted.\n");
}

// Main menu-driven program
int main()
{
    struct Node *head = NULL;
    int choice, data;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Display List\n");
        printf("3. Find and Delete Node with Second Minimum Data\n");
        printf("4. Delete List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 2:
            displayList(head);
            break;
        case 3:
            deleteSecondMinimum(&head);
            break;
        case 4:
            deleteList(&head);
            break;
        case 5:
            deleteList(&head);
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
