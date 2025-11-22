#include<stdio.h>

int main(){
    int arr1 [] = { 6,7,8,9,10};
    int arr2 [] = {1,2,3,4,5};
    int m = 5 ; 
    int n = 5 ;
    int d = m+n;
    int crr [m+n]; 
    
    int i = 0 , j = 0 , k = 0;
    //merge two sorted arrays
    while(i<m && j<n){
        if(arr1[i] < arr2[j]){
            crr[k] = arr1[i];
            i++;
        }else{
            crr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i<m){
        crr[k] = arr1[i];
            i++;k++;
    }
    while(j<n){
        crr[k]= arr2[j];
        j++;
        k++;
    }


    for(int x = 0 ; x < d ; x++){
        printf("%d ",crr[x]);
    }
    printf("\n");
    return 0;
}