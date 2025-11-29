// filepath: c:\Users\singh\OneDrive\Desktop\xyz\c_programs\quickSort.c
#include<stdio.h>

// Function prototypes
void printArray(int arr[], int n);
void swap(int arr[] , int i , int j);
int partition(int arr[] , int lo , int hi);
void quickSort(int arr[], int lo , int hi);

void printArray(int arr[], int n){
    for(int i = 0 ;i<n ;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void swap(int arr[] , int i , int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[] , int lo , int hi){
    int pivot = arr[lo] ,pivotIdx = lo;
    int smallerCount = 0;

    for(int i = lo+1 ; i <= hi ; i++){
        if(arr[i] < pivot) smallerCount ++;
    }

    // swap  the element with the pivot
    pivotIdx = lo + smallerCount;
    swap(arr,lo,pivotIdx);
    // now swap elements based on partition
    int i = lo , j = hi ;
    while (i < pivotIdx && j > pivotIdx) {
    if (arr[i] < pivot) i++;
        else if (arr[j] >= pivot) j--;
        else {
        swap(arr, i, j);
        i++;
        j--;
        }
    }   
    
    return pivotIdx;
}
void quickSort(int arr[], int lo , int hi){
    if(lo>=hi) return; 
    //partition
    int pivotIdx = partition(arr, lo , hi);
    quickSort(arr , lo , pivotIdx-1);
    quickSort(arr, pivotIdx + 1 , hi);
}
int main(){
    int arr [] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Before Sorting : ");
    printArray(arr,n);
    quickSort(arr,0,n-1);
    
    printf("After Sorting : ");
    printArray(arr,n);
    
    return 0;
}