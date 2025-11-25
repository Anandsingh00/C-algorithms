#include<stdio.h>
int main(){
    int arr[] = {3, 8, 12, 17, 25, 31, 42, 56, 64, 78, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int search = 78;
    int lo = 0;
    int hi = n-1;

    while(lo<=hi){
        int mid =lo-(hi-lo)/2;
        if(search == arr[mid]){
            printf("%d found at index %d",search , mid);
            break;
        }else if(arr[mid]>search){ 
            //update hi
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }

    return 0;
}