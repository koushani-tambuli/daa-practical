#include<stdio.h>
#define MAX 999
int main(){
    int n;
    printf("Enter no of vertex: ");
    scanf("%d",&n);

    int arr[n][n];

    printf("Enter matrix: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==0){
                arr[i][j]=MAX;
            }
        }
    }

    int visited[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    visited[0]=1;
    int edge=0,cost=0;
    int min,x,y;
    while (edge<n-1)
    {
        min=MAX;
        for(int i=0;i<n;i++){
            if(visited[i]){
                for(int j=0;j<n;j++){
                    if(!visited[j] && arr[i][j]<min){
                        min=arr[i][j];
                        x=i;
                        y=j;
                        
                    }
                }
            }
        }

        printf("%d--->%d= %d\n",x,y,arr[x][y]);
        cost+=arr[x][y];
        visited[y]=1;
        edge++;
    }
    printf("Min cost: %d",cost);
}