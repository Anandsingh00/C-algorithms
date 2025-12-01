#include<stdio.h>
int main(){
    int arr[] = { 3, 5, -2, 1, -4 };
    int n = 5;
    printf("Before Sorting: ");
    for(int i = 0; i<=n-1;i++){
        printf("%d ",arr[i] );
    }

    //Applying Selection Sort algorithm
    for(int i = 0 ; i < n ; i++){
        int minIdx = i;
        for(int j = i + 1; j <= n-1 ; j++){
            if(arr[minIdx]>arr[j]){
                minIdx = j;
            }
        }
        //swap the elements (arr[minIdx] & arr[i])
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
    printf("\n");
    printf("After Sorting: ");
    for(int i = 0; i<=n-1;i++){
        printf("%d ",arr[i] );
    }

    return 0;
}