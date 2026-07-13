#include<stdio.h>

struct Item{
    int weight;
    int profit;
    float ratio;
};

void sor(struct Item item[],int n){
    struct Item temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(item[j].ratio< item[j+1].ratio){
                temp=item[j];
                item[j]=item[j+1];
                item[j+1]=temp;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter no of items: ");
    scanf("%d",&n);

    struct Item item[n];

    printf("Enter weight and profit:\n");
    for(int i=0;i<n;i++){
        scanf("%d" "%d",&item[i].weight,&item[i].profit);
        item[i].ratio=(float)item[i].profit/item[i].weight;
    }
    int m;
    sor(item,n);
    double totalprofit=0;
    printf("Knapsack capacity: ");
    scanf("%d",&m);

    for(int i=0;i<n;i++){
        if(m>=item[i].weight){
            m-=item[i].weight;
            totalprofit+=item[i].profit;
        }
        else{
            totalprofit+=item[i].ratio * m;
            break;
        }
    }
    printf("Maximum profit= %2lf", totalprofit);

    return 0;
}