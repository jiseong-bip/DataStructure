//
//  main.c
//  test
//
//  Created by 전지성 on 2023/05/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType {
    int n; // 정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[])
{
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;
    for (i = 0; i < n; i++) {
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minpos = i;
        }
    }
    return minpos;
}

void print_shortest_path(GraphType* g, int start, int end)
{
    if (distance[end] == INF) {
        printf("There is no path from vertex %d to vertex %d\n", start, end);
        return;
    }
    
    printf("Shortest path from vertex %d to vertex %d: ", start, end);
    int path[MAX_VERTICES];
    int path_length = 0;
    int current = end;
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

void shortest_path(GraphType* g, int start)
{
    int i, u, w;
    for (i = 0; i < g->n; i++) {
        distance[i] = g->weight[start][i];
        found[i] = FALSE;
    }
    found[start] = TRUE;
    distance[start] = 0;

    for (i = 0; i < g->n - 1; i++) {
        u = choose(distance, g->n, found);
        found[u] = TRUE;
        for (w = 0; w < g->n; w++) {
            if (!found[w]) {
                if (distance[u] + g->weight[u][w] < distance[w]) {
                    distance[w] = distance[u] + g->weight[u][w];
                }
            }
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
    int start_vertex = 0; // 시작 정점
    int end_vertex = 2; // 도착 정점
    
    shortest_path(&g, start_vertex);
    print_shortest_path(&g, start_vertex, end_vertex);
    
    return 0;
}
