#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int N;

void alloc(int tempn){
  N=tempn;
}
void make_min_spanning(int n, int graph[n][n]);

void main(){
  printf("Enter the number of vertices in the graph: ");
  int tempn;

  scanf("%d", &tempn);
  alloc(tempn);
  int graph[N][N];
  int i=0, j=0;
  for(i=0; i<N; i++){
    printf("\nEnter the length of the edge of %dth node with...\n", i+1);
    for(j=0; j<N; j++){
      printf("%dth  node: ", j+1);
      scanf("%d", &graph[i][j]);
    }
  }
  make_min_spanning(N, graph);


}

void make_min_spanning(int n, int graph[n][n]) {
  /* code */
  bool included[N];
  int dis[N];
  int par[N];
  int i,j;
  for(i=0; i<N; i++){
    dis[i]=99999;
    included[i]=false;
  }
  dis[0]=0;
  par[0]=-1;

  for(i=0; i<N; i++){
    int x=0;
    int min=99999, index;
    for(j=0; j<N; j++){
      if(included[j]==false&&min>dis[j]){
        min=dis[j];
        index=j;
      }
    }

    x=index;
    included[x]=true;

    for(j=0; j<N; j++){
      if(graph[x][j]&&included[j]==false&&dis[j]>graph[x][j]){
        par[j]=x;
        dis[j]=graph[x][j];
      }
    }
  }
  printf("\n\nThe following is the constructed minimum spanning graph...\n");
  printf("\nEdge Distance\n");
  int cost=0;
  for(i=1; i<N; i++){
    printf("%d-%d    %d\n", par[i]+1, i+1, graph[i][par[i]]);
    cost+=graph[i][par[i]];
  }
  printf("\n\nThe total minimum cost of the given spanning graph is %d\n", cost);
}
