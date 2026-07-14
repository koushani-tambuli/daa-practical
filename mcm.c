#include<stdio.h>

#define MAX 10
#define IFN 999

void optimal(int i,int j,int s[MAX][MAX]){
    if(i==j){
        printf("A%d",i); return;
    }
    printf("(");
    optimal(i,s[i][j],s);
    optimal(s[i][j]+1,j,s);
    printf(")");
}

int main(){
    int n;
    printf("Enter no of matrices:");
    scanf("%d",&n);

    int p[n+1];

    printf("Enter dimensions: ");
    for(int i=0;i<=n;i++){
        scanf("%d",&p[i]);
    }

    int mm[MAX][MAX],s[MAX][MAX];
    int cost=0;

    for(int i=1;i<=n;i++){
        mm[i][i]=0;
    }

    for(int len=2;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j=i+len-1;
            mm[i][j]=IFN;
            for(int k=i;k<=j-1;k++){
                cost=mm[i][k]+mm[k+1][j]+p[i-1]*p[k]*p[j];
            
            if(cost<mm[i][j]){
                mm[i][j]=cost;
                s[i][j]=k;
            }
        }
    }
    }
    printf("No of multiplication= %d\n",mm[1][n]);
    printf("Optimal parenthesis:\n");
    optimal(1,n,s);
    return 0;

 }