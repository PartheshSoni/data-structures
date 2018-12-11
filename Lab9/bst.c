#include <stdio.h>
#include <stdlib.h>

struct node{
  struct node *left;
  struct node *right;
  int data;
}*head=NULL, *ptr=NULL;

struct node* getright(struct node *root){
  struct node *temp=root;
  while(temp->left!=NULL){
    temp=temp->left;
  }
  return temp;
}

struct node* deletenode(int d, struct node *root){

  if(root==NULL){
    return root;
  }

   if(d>root->data){
    root->right=deletenode(d, root->right);
  }
  else if(d<root->data)
    root->left=deletenode(d, root->left);
  else{
    if(root->left==NULL){
      struct node *temp=root->right;
      return temp;
    }
    else if(root->right==NULL){
      struct node *temp=root->left;
      return temp;
    }
    else{
      struct node *temp=getright(root->right);
      root->data=temp->data;
      root->right=deletenode(root->data, root->right);
    }
  }
    return root;
}

void insertnode(int d){
  struct node *newn=(struct node*)malloc(sizeof(head));
  newn->data=d;
  newn->left=NULL;
  newn->right=NULL;
  if(head==NULL){
    head=newn;
  }
  else{
    ptr=head;

    /*while(1>0){
      if(d<ptr->data){
        if(ptr->left!=NULL)
          ptr=ptr->left;

        /*else{
          ptr->left=newn;
          return;
        }*/
      /*}
      else if(d>ptr->data){
        if(ptr->right!=NULL)
          ptr=ptr->right;
        else{
          ptr->right=newn;
          return;
        }
      }
      else
        printf("The data already present in the tree!\n");
        return;
    }*/
    struct node *parent=NULL;
    while (ptr!=NULL) {
      /* code */
      parent=ptr;
      if(d==ptr->data)
        return;

      if(d>ptr->data)
        ptr=ptr->right;
      else
        ptr=ptr->left;
    }
    if(d>parent->data)
      parent->right=newn;
    else
      parent->left=newn;
  }
}

void inorder(struct node *root) {
  if(root==NULL)
    return;

  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);

}

void preorder(struct node *root){
  if(root==NULL)
    return;

  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(struct node *root) {
  /* code */
  if(root==NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

void main(){
  while(1>0){
    printf("\nEnter choice... \n");
    printf("1. Insert a node\n2. Delete a node\n3. Display\n4. Exit\nCode: ");
    int choice;
    scanf("%d", &choice);
    switch(choice){
      case 1:
        printf("Enter data for node: " );
        int  dat;
        scanf("%d", &dat);
        insertnode(dat);
        break;
      case 2:
        printf("Enter the data of the node to be deleted: ");
        int daa;
        scanf("%d", &daa);
        head=deletenode(daa, head);
        break;
      case 3:
        printf("Enter the type of traversal...\n1. Inorder\n2. Preorder\n3. Postorder\nCode: ");
        int cho;
        scanf("%d", &cho);
        switch(cho){
          case 1:
            inorder(head);
            break;
          case 2:
            preorder(head);
            break;
          case 3:
            postorder(head);
            break;
          default:
            printf("Enter valid choice next time.\n");
            break;
        }
        break;
      case 4:
        goto exi;
        break;

    }

  }
  exi:
  printf("\n");
}
