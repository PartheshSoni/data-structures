#include <stdio.h>

void insertnode(int *heap, int pos){
  int par;

  while(pos>1){
    par=pos/2;
    if(heap[par]>=heap[pos])
      break;
    else
    {
      int temp=heap[par];
      heap[par]=heap[pos];
      heap[pos]=temp;
      pos=par;
    }
  }
  /*int val=heap[pos];
  while (pos>1&&heap[pos/2]<val) {

    heap[pos]=heap[pos/2];
    pos/=2;
  }
  heap[pos]=val;*/
}

void swap(int *heap, int a, int b){
  int temp=heap[a];
  heap[a]=heap[b];
  heap[b]=temp;
}

void main(){
  printf("Enter the number of elements in the array: ");
  int n;
  scanf("%d", &n);
  int heap[n+1];
  int i;
  for(i=1; i<=n; i++){
    scanf("%d", &heap[i]);
    insertnode(heap, i);
  }
  int size=n;
  int siz=size;
  //Sorting the array, by deleting each of the root of the following iteration
  for(i=1; i<=size; i++){
    int temp=heap[1];
    heap[1]=heap[siz];
    heap[siz]=temp;
    int left, right, pos=1;
    siz--;
    int child=2*pos;
    int val=heap[pos];
    while(child<=siz){
    /* left=heap[2*pos+1];
      right=heap[2*pos+2];
      if(heap[pos]>=left&&heap[pos]>=right)
        break;
      else{
        if(heap[pos]<left&&left>right){
          swap(heap, pos, 2*pos+1);
          pos=2*pos+1;
        }
        else{
          swap(heap, pos, 2*pos+2);
          pos=2*pos+2;
        }

      }*/
      if(child<siz&&heap[child]<heap[child+1])
        child++;
      if(heap[child]<heap[child/2])
        break;
      //swap(heap, child, child/2);
      heap[child/2]=heap[child];
      child=child*2;
    }
    heap[child/2]=val;
  }
  printf("The heap sorted array is ...\n");
  for(i=1; i<=n; i++)
    printf("%d ", heap[i]);

  }
