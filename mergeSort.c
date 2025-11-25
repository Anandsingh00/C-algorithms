#include<stdio.h>

void merge(int arr[] , int lo , int mid , int hi);
void mergeSort(int arr[], int lo , int hi){
    if(lo < hi){
       int mid = (lo+hi)/2;
       mergeSort(arr,lo,mid);
       mergeSort(arr,mid+1,hi);
       merge(arr,lo,mid,hi);
    }
}

void merge(int arr[] , int lo , int mid , int hi){
    int i = lo ;
    int j = mid+1;
    int k = lo;
    //initialize a new array b with length hi+1
    int brr [hi+1] ;
    while(i<=mid && j<=hi){
        if(arr[i]<=arr[j]){
            brr[k] = arr[i];
            i++; k++; 
        }else{
            brr[k] = arr[j];
            j++;
            k++;

        }
    }
    while(i<=mid){
         brr[k] = arr[i];
            i++; k++; 
    }
    while(j<=hi){
        brr[k] = arr[j];
            j++;
            k++;
    }
    //copy brr to arr 
    for(int x =  lo ; x<=hi;x++){
        arr[x] = brr[x];
    }
}

int main(){
    int arr [] =  { 3, 5, -2, 1, -4 };
    int lo = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    int hi = n-1;
    printf("Before sorting: ");
    for(int i = 0 ; i < n ;i++){
        printf("%d ",arr[i]);
    }

    mergeSort(arr,lo,hi);
    printf("\n");
    printf("After sorting: ");
    for(int i = 0 ; i < n ;i++){
        printf("%d ",arr[i]);
    }


    return 0;

}