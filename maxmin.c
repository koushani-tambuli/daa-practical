#include<stdio.h>

struct Pair{
   int max;
   int min;
};

int comparisons = 0;

struct Pair maxmin(int arr[], int low, int high){
    struct Pair result,left,right;
    if(low==high){
        result.max=arr[low];
        result.min=arr[low];
        return result;
    }
    if(high==low+1){
        comparisons+=1; 
        if(arr[low]>arr[high]){
            result.max=arr[low];
            result.min=arr[high];
        }
        else{
            result.max=arr[low];
            result.min=arr[high];
        }
        return result;
    }

    int mid=(low+high)/2;
    left=maxmin(arr,low,mid);
    right=maxmin(arr,mid+1,high);

    comparisons++;
    result.max=(left.max>right.max)?left.max:right.max;
    comparisons++;
    result.min=(left.min<right.min)?left.min:right.min;
    
    return result;
}

int main(){
    struct Pair ans;
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    ans=maxmin(arr,0,n-1);
    printf("Maximum number is: %d\n",ans.max);
    printf("Min number is: %d\n",ans.min);
    printf("Number of comparisons = %d\n", comparisons);

    return 0;
}