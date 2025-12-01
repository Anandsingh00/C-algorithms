#include<stdio.h>
int main(){
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int n = 10;
    
    // printf("Before sorting: \n");
    // for(int i = 0 ; i<n ;i++){
    //     printf("%d " ,arr[i]);
    // }
    // printf("\n");


    //applying bubble sort algorithm
    
    for(int i = 0 ; i < n-1;i++){
        for(int j = 0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                //swap the two elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }


     printf("After sorting: \n");
    for(int i = 0 ; i<n ;i++){
        printf("%d " ,arr[i]);
    }


    return 0;
}