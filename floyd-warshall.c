#include<stdio.h>
#define IFN 999

int main(){
    int n;
    printf("Enter no of vertices: ");
    scanf("%d",&n);

    int dis[n][n];
    printf("Enter matrix:\n ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&dis[i][j]);
            if(dis[i][j]==0 && i!=j){
                dis[i][j]=IFN;
            }
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%4d",dis[i][j]);
        }
        printf("\n");
    }
    return 0;
}