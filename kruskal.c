#include<stdio.h>

struct edge{
    int src;
    int des;
    int weight;
};

struct edge e1[20];
int parent[20];

void sort(struct edge item[],int n){
    struct edge temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(item[j].weight> item[j+1].weight){
                temp=item[j];
                item[j]=item[j+1];
                item[j+1]=temp;
            }
        }
    }
}

int find(int u){
    while(parent[u]!=u){
        u=parent[u];
    }
    return u;
}

void unio(int u,int v){
    parent[find(u)]=find((v));
}

int main(){
    int v,e;
    printf("Enter no of vertex and edges: ");
    scanf("%d%d",&v,&e);

    printf("Enter source,destination,weight: ");
    for(int i=0;i<e;i++){
        scanf("%d%d%d",&e1[i].src,&e1[i].des,&e1[i].weight);
    }

    sort(e1,e);

    for(int i=0;i<v;i++){
        parent[i]=i;
    }

    int cost=0,count=0;

    for(int i=0;i<e && count<v-1;i++){
        int u=e1[i].src;
        int v=e1[i].des;
        if(find(u)!=find(v)){
            printf("%d----->%d= %d\t",e1[i].src,e1[i].des,e1[i].weight);
            cost+=e1[i].weight;
            count++;
            unio(u,v);
        }
    }
    printf("Maximum cost is: %d\t",cost);
    printf("No of edges taken: %d",count);

    return 0;


}