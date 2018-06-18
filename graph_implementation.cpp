#include<iostream>
using namespace std;

typedef struct AdjNodeList{
  int dest;
  struct AdjNodeList *next;
}AdjNodeList;

typedef struct AdjList{
  struct AdjNodeList *head;
}AdjList;

typedef struct graph{
  int v;
  struct AdjList *array;
}graph;

graph * create_graph(int v){
  graph *g = (graph *)malloc(sizeof(graph));
  g->v=v;
  g->array = (AdjList *)malloc(v * sizeof(AdjList));
  for(int i=0;i<v;i++){
    g->array[i].head = NULL;
  }
  return g;
}

void add_edge(graph *g,int src,int dest){
  AdjNodeList *nnode = (AdjNodeList *)malloc(sizeof(AdjNodeList));
  nnode->dest = dest;
  nnode->next = g->array[src].head;
  g->array[src].head = nnode;
  nnode = (AdjNodeList *)malloc(sizeof(AdjNodeList));
  nnode->dest = src;
  nnode->next = g->array[dest].head;
  g->array[dest].head = nnode;
}

void  print_graph(graph *g) {
  /* code */
  for(int i=0;i<g->v;i++){
    AdjNodeList *ptr = g->array[i].head;
    cout<<i;
    while(ptr){
      cout<<"-> "<<ptr->dest;
      ptr=ptr->next;
    }
    std::cout << '\n';
  }
}

int main(){
  int v;
  cin>>v;
  graph *g = create_graph(v);
  add_edge(g,0,1);
  add_edge(g,0,4);
  add_edge(g,1,2);
  add_edge(g,1,3);
  add_edge(g,1,4);
  add_edge(g,2,3);
  add_edge(g,3,4);
  print_graph(g);
  return 0;
}
