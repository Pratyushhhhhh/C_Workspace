#include <stdio.h> 
#include <stdlib.h>

struct Node 
{ 
    int data;
    struct Node* next;
};

void reverseList(struct Node** head)//To reverse Linked list
{ 
    struct Node* p = NULL;
    struct Node* curr = *head; 
    struct Node* p2 = NULL; 
    while (curr != NULL) {
    p2 = curr->next;    //p2=2nd Node
    curr->next = p;     //Converting current node to last node
    p = curr;           //Storing last node in p
    curr = p2;          //New current node is 2nd node
}
    *head = p;
}
void displayList(struct Node* head) 
{ 
    if (!head) 
    {
        printf("List is empty.\n"); return;
    }
    while (head != NULL)   
    {
        printf("%d -> ", head->data); 
        head = head->next;
    }
printf("NULL\n");
}

void insertEnd(struct Node** head, int data) {
     struct Node*temp;
     temp=(struct Node *)malloc(sizeof(struct Node));
    if (!temp) {
        printf("Memory allocation failed.\n");
        return;
    }
    temp->data=data;
    temp->next=NULL;
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

int main() {
struct Node* head = NULL;
int choice, value, n;
do {
printf("\n*** Menu ***\n"); 
printf("1. Insert an element\n2. Display the linked list\n3. Reverse the linked list\n4. Exit\n");
printf("Enter your choice: "); 
scanf("%d", &choice);
switch (choice) { 
    case 1:
    printf("Enter the value to insert: "); 
    scanf("%d", &value); 
    insertEnd(&head, value);
    break; 
    
    case 2:
    printf("Current Linked List:\n"); 
    displayList(head);
    break; 
    
    case 3:
    reverseList(&head);
    printf("Linked list reversed successfully.\n"); 
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
