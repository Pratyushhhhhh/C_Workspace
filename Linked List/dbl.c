#include <stdio.h> 
#include <stdlib.h> 

struct Node { 
int data; 
struct Node* next; 
struct Node* prev; 
}; 

struct Node* createNode(int data) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
newNode->data = data; 
newNode->next = NULL; 
newNode->prev = NULL; 
return newNode; 
} 

void insertAtEnd(struct Node** head, int data) //INSERTION AT END
{ 
struct Node* newNode = createNode(data); 
if (*head == NULL) { 
*head = newNode; 
} else { 
struct Node* p = *head; 
while (p->next != NULL) { 
p = p->next; 
} 
p->next = newNode; 
newNode->prev = p; 
} 
} 

void displayList(struct Node* head) //DISPLAY
{ 
if (head == NULL) { 
printf("The list is empty.\n"); 
return; 
} 
struct Node* temp = head; 
printf("Doubly Linked List: "); 
while (temp != NULL) { 
printf("%d <-> ", temp->data); 
temp = temp->next; 
} 
printf("NULL\n"); 
} 

int getLength(struct Node* head) { 
int length = 0; 
while (head != NULL) { 
        length++; 
        head = head->next; 
    } 
    return length; 
} 
 
// Function to find the intersection node 
struct Node* findIntersection(struct Node* head1, struct Node* head2) { 
    int len1 = getLength(head1); 
    int len2 = getLength(head2); 
 
    struct Node* longer = len1 > len2 ? head1 : head2; 
    struct Node* shorter = len1 > len2 ? head2 : head1; 
 
    int diff = abs(len1 - len2); 
 
    // Advance the pointer of the longer list by the difference in lengths 
    while (diff--) { 
        longer = longer->next; 
    } 
 
    // Traverse both lists together to find the intersection point 
    while (longer != NULL && shorter != NULL) { 
        if (longer == shorter) { 
            return longer; 
        } 
        longer = longer->next; 
        shorter = shorter->next; 
    } 
    return NULL; // No intersection 
} 
 
// Function to create an intersection between two lists at a given node 
void createIntersection(struct Node* head1, struct Node* head2, int intersectAt) { 
    struct Node* temp1 = head1; 
    while (intersectAt-- > 1 && temp1 != NULL) { 
        temp1 = temp1->next; 
    } 
 
    struct Node* temp2 = head2; 
    while (temp2->next != NULL) { 
        temp2 = temp2->next; 
    } 
 
    if (temp1 != NULL) { 
        temp2->next = temp1; 
        temp1->prev = temp2; 
    } 
} 
 
int main() { 
    struct Node* head1 = NULL; 
    struct Node* head2 = NULL; 
    int choice, data, intersectAt; 
 
    while (1) { 
        printf("\nMenu:\n"); 
        printf("1. Insert Node in List 1\n"); 
        printf("2. Insert Node in List 2\n"); 
        printf("3. Display List 1\n"); 
        printf("4. Display List 2\n"); 
        printf("5. Create Intersection\n"); 
        printf("6. Find Intersection\n"); 
        printf("7. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter data for List 1: "); 
                scanf("%d", &data); 
                insertAtEnd(&head1, data); 
                break; 
            case 2: 
                printf("Enter data for List 2: "); 
                scanf("%d", &data); 
                insertAtEnd(&head2, data); 
                break; 
            case 3: 
                printf("List 1: "); 
                displayList(head1); 
                break; 
            case 4: 
                printf("List 2: "); 
                displayList(head2); 
                break; 
            case 5: 
                printf("Enter the position in List 1 where List 2 should intersect: "); 
                scanf("%d", &intersectAt); 
                createIntersection(head1, head2, intersectAt); 
                printf("Intersection created.\n"); 
                break; 
            case 6: { 
                struct Node* intersection = findIntersection(head1, head2); 
                if (intersection != NULL) { 
                    printf("Intersection found at node with data: %d\n", intersection->data); 
                } else { 
                    printf("No intersection found.\n"); 
                } 
                break; 
            } 
            case 7: 
                printf("Exiting program.\n"); 
                exit(0); 
            default: 
                printf("Invalid choice! Please try again.\n"); 
        } 
    } 
    return 0; 
}
