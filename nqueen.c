#include<stdio.h>
#include<stdlib.h>

int x[20],n;

int safe(int k,int i){
    for(int j=1;j<=k-1;j++){
        if((x[j]==i) || abs(x[j]-i)==abs(j-k)){
            return 0;
        }
    }
    return 1;
}

void nqueen(int k,int n){
    for(int i=1;i<=n;i++){
        if(safe(k,i)){
            x[k]=i;
            if(k==n){
                printf("Solution is:\n ");
                for(int j=1;j<=n;j++){
                    printf("Queen %d--> row: %d, column: %d\n",j,j,x[j]);
                }
            }
            else nqueen(k+1,n);
        }
    }
}

int main(){
    int n;
    printf("Enter no of queen: ");
    scanf("%d",&n);

    nqueen(1,n);
    return 0;
}