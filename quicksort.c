#include<stdio.h>



int swap(int arr[],int a,int k){
    int t=arr[a];
    arr[a]=arr[k];
    arr[k]=t;
}

int quick(int arr[],int low,int high){
    int pivot=arr[high];
    int idx=low-1;
    for(int i=low;i<high;i++){
        if(pivot>=arr[i]){
            idx++;
            swap(arr,idx,i);
        }
    }

    idx++;
    swap(arr,idx,high);
    return idx;
}

int quicks(int arr[],int low,int high){
    if(low<high){
        int pIdx=quick(arr,low,high);
        quicks(arr,low,pIdx-1);
        quicks(arr,pIdx+1,high);
    }
}

int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    quicks(arr,0,n-1);

    printf("Sorted array: \n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0; 
}