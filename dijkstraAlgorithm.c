#include<stdio.h>
#include<limits.h>
#define V 5

int findMinDist(int dist[] , int visited[]){
    int min = INT_MAX ;
    int minIdx;

    for(int i = 0 ; i < V ; i++){
        if(visited[i] == 0 && dist[i] <= min){
            min = dist[i];
            minIdx = i;
        }
    }
    return minIdx;
}

void dijkstra(int graph[V][V],int source){
    int dist[V];
    int visited[V];


    //initialize all distance array as infinity and visited array as 0
    for(int i = 0; i < V ; i++){
        dist[i] =INT_MAX;
        visited[i] = 0;
    }
    dist[source] = 0;

    for(int count = 0;count < V-1 ;count++){
        int u = findMinDist(dist,visited);
        visited[u] = 1;

        for(int v = 0 ;v < V ; v++){
            if(graph[u][v] && dist[v] > dist[u] + graph[u][v] && !visited[v] && dist[u]!=INT_MAX){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    //print the final shortest distance
    printf("Output: ");
    for(int i = 0 ; i < V; i++){
        printf("%d ",dist[i]);
    }
}

int main(){
    //adjacency matrix
    int graph[V][V] ={
        {0, 10, 0, 5, 0},
        {10, 0, 1, 2, 0},
        {0, 1, 0, 0, 4},
        {5, 2, 0, 0, 3},
        {0, 0, 4, 3, 0}
    };

    dijkstra(graph,0); //source=0

    return 0;
}