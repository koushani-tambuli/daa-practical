#include<stdio.h>

#define IFN 999
#define MAX 10

int main(){
    int n;
    printf("Enter no of vertices: ");
    scanf("%d",&n);

    int graph[n][n],dis[n],parent[n],visited[n];

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
            if(graph[i][j]==0 && i !=j){
                graph[i][j]=IFN;
            }
        }
    }
    int src,des;
    printf("Enter source and destination: ");
    scanf("%d%d",&src,&des);

    for(int i=0;i<n;i++){
        dis[i]=IFN;
        visited[i]=0;
        parent[i]=-1;
    }

    dis[src]=0;
    

    for(int count=0;count<n-1;count++){
        int min=IFN,next=-1;

        for(int i=0;i<n;i++){
            if(visited[i]==0 && dis[i]<min){
                min=dis[i];
                next=i;
            }
        }

        if(next==-1) break;

        visited[next]=1;

        for(int i=0;i<n;i++){
            if(!visited[i] && graph[next][i] != IFN && dis[next]+graph[next][i]<dis[i]){
                dis[i]=dis[next]+graph[next][i];
                parent[i]=next;
            }
        }
    }


    int count=0,path[MAX],current=des;
    printf("Shortest distance from %d to %d is: %d ",src,des, dis[des]);
    while(current != -1){
        path[count++]=current;
        current=parent[current];
    }

    printf("Shortest path: ");
    for (int i=count-1;i>=0;i--){
        printf("%d ",path[i]);
        if(i != 0){
            printf("--->");
        }
    }
    return 0;
}