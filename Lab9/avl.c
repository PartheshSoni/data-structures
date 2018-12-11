#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
  struct node *left;
  struct node *right;
  int data;
  int hght;
}*head=NULL, *head1=NULL, *head2=NULL, *ptr=NULL;

int max(int a, int b){
  return a>b?a:b;
}

struct node* rightro(struct node *n){
  struct node *x = n->left;
  struct node *temp = x->right;

  x->right = n;
  n->left = temp;

  if(n->left!=NULL&&n->right!=NULL){
    n->hght = max(n->left->hght, n->right->hght)+1;
    x->hght = max(x->left->hght, x->right->hght)+1;
  }
  else if(n->left!=NULL&&n->right==NULL){
    n->hght = max(n->left->hght, 0)+1;
    x->hght = max(x->left->hght,0)+1;
  }
  else if(n->left==NULL&&n->right!=NULL){
    n->hght = max(0, n->right->hght)+1;
    x->hght = max(0, x->right->hght)+1;
  }
  else{
    n->hght=1;
    x->hght=1;
  }
  return x;
}

struct node* leftro(struct node *n){
  struct node *y=n->right;
  struct node *temp=y->left;

  y->left=n;
  n->right=temp;
  if(n->left!=NULL&&n->right!=NULL){
    n->hght = max(n->left->hght, n->right->hght)+1;
    y->hght = max(y->left->hght, y->right->hght)+1;
  }
  else if(n->left!=NULL&&n->right==NULL){
    n->hght = max(n->left->hght, 0)+1;
    y->hght = max(y->left->hght, 0)+1;
  }
  else if(n->left==NULL&&n->right!=NULL){
    n->hght = max(0, n->right->hght)+1;
    y->hght = max(0, y->right->hght)+1;
  }
  else{
    n->hght=1;
    y->hght=1;
  }

  return y;
}


struct node* insertnode(int d, struct node *nn){
  if(nn==NULL){
    struct node *newn=(struct node *)malloc(sizeof(head));
    newn->data=d;
    newn->hght=1;
    newn->right=NULL;
    newn->left=NULL;
    return newn;
  }
  if(d>nn->data){
    nn->right=insertnode(d, nn->right);
  }
  else if(d<nn->data)
    nn->left=insertnode(d, nn->left);
  else
    return nn;

  if(nn->left!=NULL&&nn->right==NULL)
    nn->hght=nn->left->hght+1;
  if(nn->right!=NULL&&nn->left==NULL)
    nn->hght=nn->right->hght+1;
  else if(nn->right!=NULL&&nn->left!=NULL)
    nn->hght=max(nn->left->hght, nn->right->hght)+1;
  else
    nn->hght=1;


  int bal=0;
  if(nn->left!=NULL){
    bal=nn->left->hght;
  }
  if(nn->right!=NULL)
    bal-=nn->right->hght;

  if(nn->right!=NULL&&nn->left!=NULL)
    bal=(nn->left->hght)-(nn->right->hght);

  if(nn->right==NULL&&nn->left==NULL)
    bal=0;

  if(bal>1&&nn->left!=NULL&&d<nn->left->data)
    return (rightro(nn));
  if(bal<-1&&nn->right!=NULL&&d>nn->right->data)
    return (leftro(nn));
  if(bal>1&&nn->left!=NULL&&d>nn->left->data){
    nn->left =  leftro(nn->left);
    return (rightro(nn));
  }

  if(bal<-1&&nn->right!=NULL&&d<nn->right->data){
    nn->right = rightro(nn->right);
    return (leftro(nn));
  }

  return nn;
}



void inorder(struct node *root) {
  if(root==NULL)
    return;

  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);

}

void divide(int X, struct node *nn){
  if(nn==NULL)
    return;

  if(nn->data<=X)
    head1=insertnode(nn->data, head1);
  else
    head2=insertnode(nn->data, head2);

  divide(X, nn->left);
  divide(X, nn->right);
}
void main(){
  printf("Enter the data in the AVL trees...\n");
    int cho;
  do{
    printf("Enter the data to be inserted: ");
    int da;
    scanf("%d", &da);
    head=insertnode(da, head);
    printf("Enter again?(1/0): ");

    scanf("%d", &cho);
  }while (cho!=0);

  printf("\nThe given AVL tree is as follows(Inorder Sequence)...\n");
  inorder(head);

  printf("\nEnter the value(X) for dividing the AVL tree: ");
  int X;
  scanf("%d", &X);
  divide(X, head);

  printf("\nThe inorder sequence of the AVL tree T1 is...\n");
  inorder(head1);
  printf("\nThe inorder sequence of the AVL tree T2 is...\n");
  inorder(head2);
}
