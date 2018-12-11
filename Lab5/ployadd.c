#include <stdio.h>
#include <stdlib.h>

struct node{
  int coeff;
  int powr;
  struct node *next;
}*head1=NULL, *head2=NULL, *head3=NULL, *ptr;

void display(struct node *start){
  ptr=start;
  if(start==NULL){
    printf("The equation is not mentioned.\n");
    return;
  }
  while(ptr->next!=NULL){
    printf("%dx^%d", ptr->coeff, ptr->powr);
    printf(" + ");
    ptr=ptr->next;
  }
  printf("%dx^%d\n", ptr->coeff, ptr->powr);
}
void nodeadd(int coef, int powe, int eq){
  struct node *start;
  if(eq==1)
    start=head1;
  else if(eq==2)
    start=head2;
  else
    start=head3;

    struct node *newn;
    newn=(struct node *)malloc(sizeof(head1));
    newn->coeff=coef;
    newn->powr=powe;
    if(start==NULL){
      start=newn;
      start->next=NULL;
    }
    else{
      ptr=start;
      while(ptr->next!=NULL)
        ptr=ptr->next;
      ptr->next=newn;
      ptr=ptr->next;
      ptr->next=NULL;
    }

  switch(eq){
    case 0:
      head3=start;
      break;
    case 1:
      head1=start;
      break;
    default:
      head2=start;
      break;
  }

}
void polyadd(){
  struct node *p, *q;
  p=head1;
  q=head2;

  while(p!=NULL&&q!=NULL){
    if(p->powr==q->powr){
      if((p->coeff)+(q->coeff)!=0){
        nodeadd(p->coeff+q->coeff, p->powr, 0);
        p=p->next;
        q=q->next;
      }
      else{
        p=p->next;
        q=q->next;
      }

    }
      else if((p->powr)>(q->powr)){
        nodeadd(p->coeff, p->powr, 0);
        p=p->next;
      }
      else{
        nodeadd(q->coeff, q->powr, 0);
        q=q->next;
      }
  }
  if(p||q){
    if(p!=NULL)
      while(p!=NULL) {
        /* code */
        nodeadd(p->coeff, p->powr, 0);
        p=p->next;
      }

      else
      while (q!=NULL) {
        /* code */
        nodeadd(q->coeff, q->powr, 0);
        q=q->next;
      }
    if(p==NULL&&q==NULL){
      if((p->coeff>q->coeff)){
        nodeadd(p->coeff, p->powr, 0);
        nodeadd(q->coeff, q->powr, 0);
      }
      else{
          nodeadd(q->coeff, q->powr, 0);
          nodeadd(p->coeff, p->powr, 0);
      }
    }
  }
  /*if(p==NULL){
    if(q!=NULL)
    while(q!=NULL){
      polyadd(q->coeff, q->powr, 0);
      q=q->next;
    }
  }
  if(q==NULL)
    if(p!=NULL)
    while(p!=NULL){
      polyadd(p->coeff, p->powr, 0);
      p=p->next;
    }*/
}

void main(){
  printf("Enter the polynomial 1...\n");
  int choice;
  do {
    printf("Enter the coeff: ");
    int coeff;
    scanf("%d", &coeff);
    printf("Enter the power: ");
    int powe;
    scanf("%d", &powe);
    nodeadd(coeff, powe, 1);
    printf("Enter again?(1/0)");
    scanf("%d", &choice);
  } while(choice!=0);
  printf("The entered 1st equation is...\n");
  display(head1);
  printf("Enter  the polynomial 2...\n");
  do {
    /* code */
    printf("Enter the coeff: ");
    int coeff;
    scanf("%d", &coeff);
    printf("Enter the power: ");
    int powe;
    scanf("%d", &powe);
    nodeadd(coeff, powe, 2);
    printf("Enter again?(1/0)");
    scanf("%d", &choice);
  } while(choice!=0);
  printf("The entered 2nd equation is...\n");
  display(head2);
  polyadd();
  printf("The equation formed after adding 1st and 2nd equation is...\n");
  display(head3);
}
