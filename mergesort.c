#include<stdio.h>

void merge(int arr[],int low,int mid,int high){
    int j=mid+1;
    int i=low;
    int k=0;
    int temp[(high-low)+1];
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else temp[k++]=arr[j++];
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=high){
        temp[k++]=arr[j++];
    }
    
    for(int i=0;i<k;i++){
        arr[i+low]=temp[i];
    }
}

void merges(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        merges(arr,low,mid);
        merges(arr,mid+1,high);
        merge(arr,low,mid,high);
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

    merges(arr,0,n-1);

    printf("Sorted array: \n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0; 
}