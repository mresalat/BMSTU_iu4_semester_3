#include<stdio.h>
#include<string.h>
struct Edges{
    int vertice1;
    int vertice2;
};
int main()
{
    int v,e;
    printf("No. of vertices: ");
    scanf("%d",&v);
    printf("No. of edges: ");
    scanf("%d",&e);
    printf("connection between two vertices: \n");
    int graph[v+1][v+1];
    memset(graph,0,sizeof(graph));
    struct Edges E[e];
    for(int i=0;i<e;i++){
        //int a,b;
        scanf("%d %d",&E[i].vertice1,&E[i].vertice2);
        graph[E[i].vertice1][E[i].vertice2]=1;
        graph[E[i].vertice2][E[i].vertice1]=1;

    }
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++)printf("%d ",graph[i][j]);
        puts("");
    }
}
