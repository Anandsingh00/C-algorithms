#include <stdio.h>
struct Item{
    int profit ;
    int weight;
};

void sortItems(struct Item items[],int n){
    for(int i = 0;i < n-1 ; i++){
        for(int j = 0 ; j< n-i-1 ; j++){
            double r1 = (double) items[j].profit / items[j].weight;
            double r2 = (double) items[j+1].profit / items[j+1].weight;
            if(r1 < r2){
                //swap 
                struct Item temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }
}

double   findMaxProfit(struct Item items[],int n,int capacity){
    sortItems(items,n);
    double totalProfit = 0.0;
    for(int i = 0 ; i < n  ; i++){
        if(capacity == 0 ) break;

        if(items[i].weight <= capacity){
            totalProfit +=  items[i].profit;
            capacity -= items[i].weight;
        }else{
            // take fraction of the weight
            double fraction = (double)capacity / items[i].weight;
            totalProfit += fraction * items[i].profit;
            capacity=0;
        }
    }
    return totalProfit;

}

int main(){
    struct Item items[] = {
        {100,20},
        {120,30},
        {60,10}
    };
    int capacity = 50 ; 
    int n = sizeof(items) / sizeof(items[0]);
    double profit = findMaxProfit(items,n,capacity);
    printf("Maximum Profit is: %.2f",profit);
    return 0;
}