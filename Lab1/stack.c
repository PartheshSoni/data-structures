#include <stdio.h>


int max=100;
int *stk;
int tos=-1;
void alloc(int range){
    stk=(int *)malloc(range*sizeof(int));
    return;
}

void push(int value){
    if(tos==99){
        printf("\nSorry! The stack is full.");
        return;
    }
    else{
        tos++;
        stk[tos]=value;
        printf("\nValue popped successfully!");

    }
    return;
}

void pop(){
    if(tos==-1){
        printf("\nThe stack is already empty.");
        return;
    }
    else{
        printf("\nValue popped: %d", stk[tos]);
        tos--;
    }
    return;
}
void peep(int index){
    if(index>=max||index<0||index>tos){
        printf("\nInvalid index, try again next time.");
    }
    else{
        printf("\nThe value at the index %d, is %d", index, stk[index]);
    }
    return;
}
void display(){
    printf("\nVisual representation of the stack...\n");
    int i=0;
    printf("\n --");
    for(i=0; i<=tos; i++){
        printf("\n|%d|", stk[i]);
        printf("\n --");
    }
    return;
}
void removei(int index){
    if(index<0||index>tos){
        printf("\nInvalid index, try again next time.");
        return;
    }
    int i=0;
    for(i=index+1; i<=tos; i++){
        stk[i-1]=stk[i];
    }
    tos--;
    return;
}
void clearstk(){
    tos=-1;
    return;
}
void amending(int index, int value){
    stk[index]=value;
    return;
}
void main(){
    printf("What will be the maximum range of the stack?: ");
    int range;
    scanf("%d", &range);
    alloc(range);
    while(1>0){
    int choice;
    printf("\nEnter one of the following choices...\n1. Push\n2. Pop\n3. Peep\n4. Display\n5. Amend\n6. Remove\n7. Clear Stack\nCode: ");
    scanf("%d", &choice);
    switch(choice){
    case 1:
        printf("\nEnter the value to be pushed: ");
        int val;
        scanf("%d", &val);
        push(val);
        break;
    case 2:
        pop();
        break;

    case 3:
        printf("\nEnter the index of element to be displayed: ");
        int index;
        scanf("%d", &index);
        peep(index);
        break;
    case 4:
        display();
        break;
    case 5:
        printf("\nEnter the index and the value to be amended(eg. index value): ");
        int value;
        int ind;
        scanf("%d %d", &ind, &value);
        amending(ind, value);
        break;
    case 6:
        printf("\nEnter the index of the element to be removed: ");
        int indi;
        scanf("%d", &indi);
        removei(indi);
        break;
    case 7:
        printf("\nDo you really want to clear the whole stack? (Y/n)");
        char ch;
        scanf("%c", &ch);
        scanf("%c", &ch);
        if(ch=='Y'||ch=='y'){
            clearstk();
        }
        break;
    default:
        printf("\nInvalid choice! Please enter valid choice.");
        break;
    }

    printf("\nPress 1 to continue and 0 to stop: ");
    int cho;
    scanf("%d", &cho);
    system("cls");
    if(cho==0)
        break;
    }

    }

