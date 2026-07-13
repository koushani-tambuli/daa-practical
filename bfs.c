#include<stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int Q[MAX];
int front=-1;
int rear=-1;

void enqueue(int vertex){
    if(rear==MAX-1){
        printf("Overflow");
        return;
    }
    if(front==-1) front=0;
    Q[++rear]=vertex;
}

int dequeue(){
    return Q[front++]; 
}

int isEmpty(){
    if(front>rear) return 0;
    return 1;
}

void bfs(int start,int n){
    for(int i=0;i<n;i++) visited[i]=0;

    visited[start]=1;
    enqueue(start);
    while(isEmpty()){
        int u=dequeue();
        printf("%d, ",u);

        for(int i=0;i<n;i++){
            if(graph[u][i]==1 && visited[i]==0){
                visited[i]=1;
                enqueue(i);
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the no of vertex: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    int start;
    printf("Enter start vertex: ");
    scanf("%d",&start);

    bfs(start,n);
    return 0;
}