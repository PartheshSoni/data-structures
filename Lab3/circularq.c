#include <stdio.h>

int *queue;
int front=0;
int rear=-1;
int size;

void alloc(int n){
    queue=(int *)malloc(sizeof(int)*n);
    size=n;
}

void insert(int ele){

    if((rear+1)%size==front&&rear!=-1)
        printf("\nQueue is overflowed! Operation canceled.");
    else{
        rear++;
        if(rear==size)
            rear=0;
        queue[rear]=ele;
        printf("\nOperation successful");
    }
}

void deletee(){
     if(front-1==rear)
        printf("\nQueue underflowed! Operation canceled.");

    else if(front==rear){
        printf("\nDeleted element: %d",queue[front]);
        front=0;
        rear=-1;
    }
    else if(front==size-1){
        printf("\nDeleted element: %d", queue[front]);
        front=0;
    }

        else{
        printf("\nDeleted element: %d",queue[front] );
        front++;
    }
}
void main(){
    printf("\nEnter the maximum range of the queue: ");
    int range=0;
    scanf("%d", &range);
    alloc(range);
    printf("\nPress Ctrl+Z to exit...\n");
    while(1>0){
            int choice;
            printf("\nEnter a choice...\n1. Insert\n2. Delete\nCode: ");
            scanf("%d", &choice);
            switch(choice){
            case 1:
                printf("\nEnter the element to be inserted: ");
                int ele;
                scanf("%d", &ele);
                insert(ele);
                break;
            case 2:
                printf("\nDeleting element...");
                deletee();
                break;
            }
    }


}
