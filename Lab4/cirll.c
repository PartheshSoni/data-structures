#include <stdio.h>


struct node{
    int data;
    struct node *next;
}*x=NULL;
struct node *head=NULL;



void display(){
x=head;
if(x==NULL){
    printf("\nEmpty linked list!\n");
    return;
}
printf("\n");
while(x->next!=head){
    printf("%d ", x->data);
    x=x->next;
}
printf("%d\n\n", x->data);
}


void insertBeg(){
    printf("\nEnter the data to be inserted: ");
    int d;
    scanf("%d", &d);

    struct node *newn=(struct node *)malloc(sizeof(struct node));
    newn->data=d;
    if(head==NULL){
        x=newn;
        x->next=x;
        head=x;

    }
    else{
        while(x->next!=head)
            x=x->next;
        x->next=newn;
        newn->next=head;
        head=newn;
    }
    display();
}

void insertEnd(){
    printf("\nEnter the data to be added: ");
    int d;
    scanf("%d", &d);
    struct node *newn=(struct node *)malloc(sizeof(struct node));
    newn->data=d;
    if(head==NULL){
        x=newn;
        x->next=x;
        head=x;
    }
    else{
        x=head;
        while(x->next!=head){
            x=x->next;
        }
        x->next=newn;
        x=x->next;
        x->next=head;
    }
    display();
}

void insertAfter(){
    printf("\nEnter the element after which element needs to be inserted: ");
    int locate;
    scanf("%d", &locate);
    printf("\nEnter the element to be inserted: ");
    int d;
    scanf("%d", &d);
    struct node *newn=(struct node *)malloc(sizeof(struct node));
    newn->data=d;
    x=head;
    int flag=0;
    while(x->next!=head){
        if(x->data==locate){
            flag=1;
            break;
        }
        x=x->next;
    }
    if(flag==0){
        printf("Element not found. Operation cancelled!");
        return;
    }
    newn->next=x->next;
    x->next=newn;
display();

}
void deleteStart(){
    x=head;

    if(head==NULL){
        printf("\nThe list is empty. Operation failed!");
        return;
    }
    else{
        x=head;
        while(x->next!=head){
            x=x->next;
        }
        if(x==head&&x->next==head){
            x=NULL;
            head=NULL;
        }
        x->next=head->next;
        head=head->next;
    }
    display();
}

void deleteEnd(){
    if(head==NULL)
    {
        printf("\nThe list is empty. operation failed!");
    }
    else{
    x=head;
    while((x->next)->next!=head){
        x=x->next;
    }
    if(x==head&&x->next==head){
        x=NULL;
        head=NULL;
    }
    else
    x->next=head;
    }
display();
}

void deleteAfter(){
    if(head==NULL)
    {
        printf("\nThe list is empty. Operation failed!");
        return;
    }
    printf("\nEnter the element after which the element is be deleted: ");
    int locate;
    scanf("%d", &locate);

    int flag=0;
    x=head;
    if(x->data==locate){
        flag=1;
        goto here;
        }
    while(x->next!=head){

        x=x->next;
         if(x->data==locate){
                flag=1;
            break;
            }
    }
    if(flag==0){
        printf("\nThe element is not found. Operation cancelled!");
        return;
    }
    if(x->next==head&&x==head)
    {
     x=NULL;
     head=NULL;
        }
    else if(x->next==head){
        x->next=head->next;
        head=head->next;
    }
    else{
    here:
    x->next=x->next->next;

    }
    display();
}
void main(){
while(1>0){
        printf("\nEnter choice...\n1. Insert\n2. Delete\n3. Display\nCode: ");
        int choice1;
        scanf("%d", &choice1);
        switch(choice1){
    case 1:
        printf("\nINSERTION\nWhich type of insertion...\n1. Insert at begining\n2. Insert at end\n3. Insert after an element\nCode: ");
        int choice2;
        scanf("%d", &choice2);
        switch(choice2){
            case 1:
                insertBeg();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                insertAfter();
                break;



            default:
                printf("\nPlease enter a valid choice!");
            }

        break;

    case 2:
        printf("\nDELETION\nEnter type of deletion...\n1. Delete from start.\n2. Delete from end.\n3. Delete after an element.\nCode: ");
        int choice3;
        scanf("%d", &choice3);
        switch(choice3){
            case 1:
            deleteStart();
            break;
            case 2:
            deleteEnd();
            break;
            case 3:
            deleteAfter();
            break;
            default:
            printf("\nEnter a valid choice.");
            break;
        }

        case 3:
        printf("\nDISPLAY:");
        display();
        break;

        default:
        printf("\nEnter a valid choice.");
        }
        }


}
