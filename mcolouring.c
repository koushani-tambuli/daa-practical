#include<stdio.h>
int graph[20][20];
int x[20];
int n,m;

void next(int k){
    int j;
    while(1){
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0) return;
        for( j=1;j<=n;j++){
            if(graph[k][j]==1 && x[k]==x[j]) break;
        }
        if(j==n+1) return;
    }
}

void mcolour(int k){
    while(1){
        next(k);
        if(x[k]==0) return;
        if(k==n){
            printf("Solution: ");
            for(int j=1;j<=n;j++){
                printf("%d ",x[j]);
            }
            printf("\n");
        }
        else{
            mcolour(k+1);
        }
    }
}

int main(){
    printf("Enter no of vertex: ");
    scanf("%d",&n);

    printf("enter matrix: ");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("Enter no of colour: ");
    scanf("%d",&m);

    for(int i=1;i<=n;i++){
        x[i]=0;
    }
    mcolour(1);
    return 0;
}