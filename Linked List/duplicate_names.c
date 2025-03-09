#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

struct Node
{
    char name[50];
    int rollNo;
    struct Node *next;
};

void deleteDuplicates(struct Node *head)//To delete duplicate names
{
    struct Node *current = head, *prev = NULL, *temp;
    while (current != NULL)
    {
        prev = current;//following pointer
        temp = current->next;
        while (temp != NULL)
        {
            if (strcmp(current->name, temp->name) == 0)//Checking if same name
            {
                prev->next = temp->next;//Connecting previous node to next node
                free(temp);//Deleting duplicate node
                temp = prev->next;//connecting temp to next node
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}
void displayList(struct Node *head)
{
    if (!head)
    {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL)
    {

        printf("Name: %s, Roll No: %d\n", head->name, head->rollNo);
        head = head->next;
    }
}
void insertEnd(struct Node **head, char *name, int rollNo)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    strcpy(temp->name, name);
    temp->rollNo = rollNo;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    struct Node* p = *head;
    while (p->next != NULL)
    p = p->next; 
    p->next = temp;
}
int main()
{
    struct Node *head = NULL;
    int choice, rollNo;
    char name[50];
    do
    {
        printf("\n*** Menu ***\n");
        printf("1. Insert a student\n");
        printf("2. Display the linked list\n");
        printf("3. Remove duplicate names\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter student's name: ");
            scanf("%s", name);
            printf("Enter roll number: ");
            scanf("%d", &rollNo);
            insertEnd(&head, name, rollNo);
            break;
        case 2:
            printf("Current Linked List:\n");
            displayList(head);
            break;
        case 3:
            deleteDuplicates(head);
            printf("Duplicate names removed successfully.\n");
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        }
    } while (choice != 4);
    return 0;
}