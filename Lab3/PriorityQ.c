#include <stdio.h>
int **queue;
int *front;
int *rear;

void pause(){
    int i=0;
    for(; i<999999999; i++);
}
void alloc(int pri, int max){
    queue=(int **)malloc(pri*sizeof(int *));
    int i=0;
    for(i=0; i<pri; i++)
        queue[i]=(int *)malloc(sizeof(int)*max);
    front=(int *)malloc(sizeof(int)*pri);
    rear=(int *)malloc(sizeof(int)*pri);

    for(i=0; i<pri; i++){
        front[i]=0;
        rear[i]=-1;
    }

}

void enqueue(int p, int v, int max, int tprio){
    if(p>tprio){
        printf("\nThe given Priority does not exists.");
        return;
    }
    if(rear[p]==max-1){
        printf("\nGiven Priority input is full, try another Priority.");
        return;
    }
    rear[p]++;
    queue[p][rear[p]]=v;
    printf("\nEnqueue successful!\n\n");
    int j=0, i=0;
    printf("\nVisual representation of queue...\n\n");
    for(i=0; i<tprio; i++){
            if(rear[i]==-1)
            continue;
        for(j=front[i]; j<=rear[i]; j++){
            printf("%d ", queue[i][j]);
        }
        printf("\n");
    }
    pause();
}

void dequeue(int m,int p){
    int i=0, j=0, flag=0;
    for(i=0; i<p; i++){
        if(front[i]==0&&rear[i]==-1)
            continue;
        else if(front[i]==rear[i]){
            printf("\nElement: %d", queue[i][front[i]]);
            flag=1;
            front[i]=0;
            rear[i]=-1;
            pause();
            break;
        }
        else{
            printf("\nElement: %d", queue[i][front[i]]);
            front[i]++;
            flag=1;
            pause();
            break;

        }

}
if(flag==1){
    printf("\nVisual representation of queue...\n\n");
    for(i=0; i<p; i++){
            if(rear[i]==-1)
            continue;
        for(j=front[i]; j<=rear[i]; j++){
            printf("%d ", queue[i][j]);
        }
        printf("\n");
    }
}
    if(flag==0)
        printf("\nThe queue is already empty! Dequeue not possible.");
    pause();
}
void main(){
    int prio;
    printf("\nEnter the number of Priorities: ");
    scanf("%d", &prio);
    printf("\nEnter the maximum number of elements for a single Priority: ");
    int maxele;
    scanf("%d", &maxele);
    alloc(prio, maxele);
    while(1>0){
         system("cls");
        printf("\nEnter the operation:\n1. Enqueue\n2. Dequeue\n3. Exit\nCode: ");
        int option;
        scanf("%d", &option);
        switch(option){
        case 1:
            printf("\nEnter the Priority and value to be inserted:(for eg:p v) ");
            int p, v;
            scanf("%d%d", &p, &v);
            enqueue(p-1, v, maxele, prio);
            break;
        case 2:
            dequeue(maxele, prio);
            break;
        case 3:
            goto over;
            break;
        }
    }
    over:
        printf("\nEnd of program.\n");
}
