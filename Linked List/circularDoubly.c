#include<stdio.h>
#include<stdlib.h>

struct CDN
{
    struct CDN *prev;
    int info;
    struct CDN *next;
};
struct CDN *insert(struct CDN *head)
{
    struct CDN *temp;
    temp=(struct CDN *)malloc(sizeof(struct CDN));
    if(temp==NULL)
        printf("Memory not available");
    else if(head==NULL)
    {
        temp->prev=temp->next=temp;
        head=temp;
        printf("Enter value");
        scanf("%d",temp->info);   
    }
    else{
        temp->next = head->next;
        temp->prev = head->prev;
        head->prev->next = temp;
        head->prev = temp;
        
        printf("Enter value");
        scanf("%d",temp->info);
    }
    return head;
}
 
struct CDN *deleteLast(struct CDN *head)
{
    struct CDN *p1,*p2;
    if (head==NULL)
        printf("Empty list");
    else if (head->next=head)
    {
        p1=head;
        head=NULL;
        printf("Data is ",p1->info);
        free(p1);
    }
    else 
    {
        p1=head;
        do
        {
            p2=p1;
            p1=p1->next;
        }while(p1!=head);
        p2->next=head;
        printf("%d",p1->info);
        free(p1);

    }
    return head;
}
void display(struct CDN *head)
{
    struct CDN *p;
    p=head;
    if(head==NULL)
    {
        printf("Empty\n");
    }
    else{
    do {
        printf("%d ", p->info);
        p = p->next;
    } while (p != head);
    printf("\n");
    }
}
int main()
{
    struct CDN *head=NULL;
    int ch;
    do{
    printf("Enter 1 for insertion \n 2 for Deletion \n 3 for Display \n any other to exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        head=insert(head);
        break;

        case 2:
        head=deleteLast(head);
        break;

        case 3:
        display(head);
        break;

        default:
        exit(0);
    }
    }while(1);

    }
