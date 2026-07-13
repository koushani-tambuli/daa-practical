#include<stdio.h>

struct job{
    char id;
    int profit;
    int deadline;
};

void sor(struct job item[],int n){
    struct job temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(item[j].profit< item[j+1].profit){
                temp=item[j];
                item[j]=item[j+1];
                item[j+1]=temp;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter no of jobs: ");
    scanf("%d",&n);

    struct job j1[n];

    printf("Enter job id,profit and deadline: \n");
    for(int i=0;i<n;i++){
        scanf(" %c",&j1[i].id);
        scanf("%d",&j1[i].profit);
        scanf("%d",&j1[i].deadline);
    }

    sor(j1,n);

    int maxdeadline=0;
    for(int i=0;i<n;i++){
        if(j1[i].deadline>maxdeadline) maxdeadline=j1[i].deadline;
    }

    int fill[maxdeadline+1];
    char slot[maxdeadline+1];
    
    for(int i=0;i<=maxdeadline;i++){
        fill[i]=0;
        slot[i]='-';
    }
    int tprofit=0;

    for(int i=0;i<n;i++){
        for(int j=j1[i].deadline;j>=1;j--){
            if(fill[j]==0){
                fill[j]=1;
                slot[j]=j1[i].id; 
                tprofit+=j1[i].profit;
                break;
            }
        }
    }
    printf("Selected Jobs: ");
for(int i = 1; i <= maxdeadline; i++){
    if(fill[i])
        printf("%c ", slot[i]);
}
    
    printf("Total profit: %d",tprofit);
    return 0;
}