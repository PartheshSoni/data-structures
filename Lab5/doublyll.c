#include <stdio.h>

struct node{
    int data;
    struct node *next;
    struct node *pre;
}*x=NULL;

struct node *head=NULL;
struct node *last=NULL;

void display(){
x=first;
if(x==NULL&&first==NULL)
{
    printf("The linked list is empty.");
    return;
}
printf("\n");
while(x->next!=NULL){
    printf("%d ", x->data);
    x=x->next;
}
printf("%d\n\n");
}

void insertBeg(){
    int d;
    printf("Enter the data: ");
    scanf("%d", &d);

    struct node *newn=(struct node*)malloc(sizeof(struct node));
    newn->data=d;
    if(head==NULL){
        x=newn;
        head=x;
        last=head;
    }
    else{
        x=head;
        x->pre=newn;
        x=x->pre;
        x->next=head;
        head=x;
    }
}

void insertEnd(){
    int d;
    printf("Enter the data: ");
    scanf("%d", &d);
    struct node *newn=(struct node*)malloc(sizeof(struct node));
    newn->data=d;
    if(head==NULL){
        x=newn;
        head=x;
        last=head;
    }
    else{
        x=head;
        while(x->next!=NULL){
            x=x->next;
        }
        newn->pre=x;
        x->next=newn;
        last=newn;
    }
}
void insertAfter(){
    printf("Enter the element after you want to insert your data: ");
    int locate;
    scanf("%d", &locate);
    printf("Enter the data to be inserted: ");
    int d;
    scanf("%d", &d);

    struct node *newn=(struct node *)malloc(sizeof(struct node));
    newn->data=d;
    if(head==NULL){
        printf("There are no element in the list. Inserting at start...\n");
        x=newn;
        head=x;
        last=head;
    }
    else{
        x=head;
        int flag=0;

        while(x->next!=NULL){
            if(x->data==locate)
            {
                flag=1;
                break;
            }
            else
                x=x->next;
        }
        if(flag==0){
            printf("There is no such element! Operation failed.")   //Searching from both sides should be a feature.
            return;
        }
        else{
            if(x!=last){
            newn->next=x->next;
            x->next->pre=newn;
            newn->pre=x;
            x->next=newn;
            }
            else{
                newn->pre=x;
               x->next=newn;
                last=newn;
            }

        }

    }
}

void insertBefore(){
    printf("Enter the element before which the element is to be added: ");
    int locate;
    scanf("%d", &locate);

    printf("Enter the data to be inserted: ");
    int d;
    scanf("%d", &d);

    struct node *newn=(struct node *)malloc(sizeof(struct node));
    newn->data=d;
    if(head==NULL){
        printf("The linked list is empty! Inserting the data at the beginning.");
        head=newn;
        last=newn;
    }
    else{
        x=head;
        int flag=0;
        while(x->next!=NULL){
            if(x->data==d){
                flag=1;
                break;
            }

        }
        if(flag==0){
            printf("The element is not there in the list. Operation failed!");
            return;
        }
        else{
            if(x!=head){
                newn->next=x;
                newn->pre=x->pre;
                newn->pre->next=newn;
                x->pre=newn;
                }
            else{
                newn->next=x;
                x->pre=newn;
                head=x;
            }
        }
    }


}

void deleteStart(){
    if(head==NULL){
        printf("The linked list is empty. Operation failed!");
        return;
    }
    else{
        if(head==last){
            head=NULL;
            last=NULL;

        }
        else{
            x=head;
            x->next->pre=NULL;
            head=x->next;
        }
    }
}

void deleteEnd(){
    if(head==NULL){
        printf("The linked list is empty. Operation failed!");
        return;
    }
    else{
        if(head==last){
            head=NULL;
            last=NULL;
        }
        else{
            x=last;
            x->pre->next=NULL;
            last=x->pre;
        }
    }
}

void deleteAfter(){
    printf("Enter the element after which the data is to be deleted: ");
    int locate;
    scanf("%d", &locate);
    if(head==NULL){
        printf("The linked list is empty. Operation failed!");
        return;
    }
    else{
        int flag=0;
        x=head;
        while(x->next!=NULL){
            if(x->data==locate){
                flag=1;
                break;
            }
            x=x->next;
        }
        if(x==last){
            printf("There is no element after given element. Operation failed!");
            return;
        }

    }
}



void main(){
    while(1>0){
        printf("Enter your choice...\n1. Insertion\n2. Deletion\n3. Display\nCode: ");
        int choice;
        scanf("%d", choice);
        switch(choice){
    case 1:
        printf("\nINSERTION\nWhich type of insertion...\n1. Insert at beginning\n2. Insert at end\n3. Insert after an element\n4. Insert before an element\nCode: ");
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
            case 4:
                insertBefore();
                break;


            default:
                printf("\nPlease enter a valid choice!");
            }

        break;

    case 2:
        printf("\nDELETION\nEnter type of deletion...\n1. Delete from start.\n2. Delete from end.\n3. Delete after an element.\n4. Delete before an element\nCode: ");
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
            case 4:
            deleteBefore();
            break;
            default:
            printf("\nEnter a valid choice.");
            break;
        }

        case 3:
        pirntf("\nDISPLAY:")
        display();
        break;

        default:
        printf("\nEnter a valid choice.");
        }
        }
    }
}
