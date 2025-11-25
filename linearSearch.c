#include<stdio.h>
int main(){
    int arr[] = {37, 84, 12, 59, 6, 91, 48, 23, 75, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int search = 91;
    for(int  i = 0 ; i < n ; i++){
        if(arr[i] == search){
            printf("%d find at index : %d" , search,i);
            break;
        }
    }
    return 0;
}