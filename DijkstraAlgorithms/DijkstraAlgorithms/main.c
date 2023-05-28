//
//  main.c
//  DijkstraAlgorithms
//
//  Created by 전지성 on 2023/05/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType {
    int n;// 정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[])
{
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;
    for(i = 0; i < n; i++){
        if(distance[i] < min && !found[i]){
            min = distance[i];
            minpos = i;
        }
    }
    return minpos;
}

void print_status(GraphType* g)
{
    static int step = 1;
    printf("STEP %d: ", step++);
    printf("distance: ");
    for (int i = 0; i < g->n; i++) {
        if(distance[i] == INF)
            printf(" * ");
        else
            printf("%2d ", distance[i]);
    }
    printf("\n");
    printf("    found:  ");
    for(int i = 0; i < g->n; i++)
        printf("%2d ", found[i]);
    printf("\n\n");
}

void shortest_path(GraphType* g, int start)
{
    int i, u, w;
    for(i = 0; i < g ->n; i++){
        distance[i] = g->weight[start][i];
        found[i] = FALSE;
    }
    found[start]=TRUE;
    distance[start] = 0;
    
    for(i = 0; i<g->n; i++){
        print_status(g);
        u = choose(distance, g->n, found);
        found[u] = TRUE;
        for(w=0; w<g->n;w++)
            if(!found[w])
                if(distance[u] + g->weight[u][w] < distance[w])
                    distance[w] = distance[u] + g->weight[u][w];
    }
}

void print_shortest_path(GraphType* g, int start)
{
    printf("Shortest paths from vertex %d:\n", start);
    for (int i = 0; i < g->n; i++) {
        if (distance[i] == INF) {
            printf("There is no path from vertex %d to vertex %d\n", start, i);
        } else {
            printf("Path from vertex %d to vertex %d: ", start, i);
            int path[MAX_VERTICES];
            int path_length = 0;
            int current = i;
            path[path_length++] = current;
            while (current != start) {
                int prev = -1;
                for (int j = 0; j < g->n; j++) {
                    if (g->weight[current][j] != INF && distance[current] == distance[j] + g->weight[current][j]) {
                        prev = j;
                        break;
                    }
                }
                if (prev == -1) {
                    printf("Error: Failed to find path.\n");
                    return;
                }
                current = prev;
                path[path_length++] = current;
            }
            for (int j = path_length - 1; j >= 0; j--) {
                printf("%d ", path[j]);
            }
            printf("\n");
        }
    }
}



int main(void)
{
    GraphType g = { 7,
                    {{0,7,INF,INF, 3,10,INF},
                    {7, 0, 4, 10, 2, 6,INF},
                    {INF,4, 0,2,INF,INF,INF},
                    {INF,10, 2, 0, 11, 9, 4},
                    {3, 2, INF, 11, 0,INF, 5},
                    {10, 6, INF, 9,INF, 0,INF},
                    {INF,INF,INF, 4, 5,INF, 0}}
        
    };
    shortest_path(&g, 0);
    print_shortest_path(&g, 0);

    return 0;
    
}
