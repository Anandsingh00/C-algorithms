#include<stdio.h>
int n,capacity=8;
int weight[4] = {2,3,4,5};
int profit[4] = {3,5,6,10};  
int maxProfit = 0;

void knapsack(int idx, int currentWeight , int currentProfit){

    //if weight exceeds capacity return
    if(currentWeight > capacity){
        return ;
    }
    //update maximumprofit so far
    if(currentProfit > maxProfit){
        maxProfit = currentProfit;
    }

    //if all items are processed then return
    if(idx == n){
        return;
    }
    
    // include the current item
    knapsack(idx + 1,currentWeight + weight[idx] , currentProfit + profit[idx]);

    //exclude the current item
    knapsack(idx + 1, currentWeight,currentProfit);

}

int main(){
    n=4; // 4 objects are there
    
    knapsack(0,0,0);
    printf("Maximum Profit: %d",maxProfit);

    return 0;
}