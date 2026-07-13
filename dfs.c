#include<stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int S[MAX];
int top=-1;


void push(int vertex){
    if(top==MAX-1){
        printf("Overflow");
        return;
    }
    S[++top]=vertex;
}

int pop(){
    return S[top--]; 
}

int isEmpty(){
    if(top==-1) return 0;
    return 1;
}

void bfs(int start,int n){
    for(int i=0;i<n;i++) visited[i]=0;

    visited[start]=1;
    push(start);
    while(isEmpty()){
        int u=pop();
        printf("%d, ",u);

        for(int i=n-1;i>=0;i--){
            if(graph[u][i]==1 && visited[i]==0){
                visited[i]=1;
               push(i);
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