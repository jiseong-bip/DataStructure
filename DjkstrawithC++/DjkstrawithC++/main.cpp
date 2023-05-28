//
//  main.cpp
//  DjkstrawithC++
//
//  Created by 전지성 on 2023/05/28.
//

#include <iostream>
#include <vector>
#include <limits>

#define INF std::numeric_limits<int>::max()

struct GraphType {
    int n;  // 정점의 개수
    std::vector<std::vector<int>> weight;
};

std::vector<int> distance;
std::vector<bool> found;

int choose(const std::vector<int>& distance, int n, const std::vector<bool>& found) {
    int min = INF;
    int minpos = -1;
    for (int i = 0; i < n; i++) {
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minpos = i;
        }
    }
    return minpos;
}

void print_status(GraphType* g) {
    static int step = 1;
    std::cout << "Step" << step++;
    std::cout << " distance: " ;
    
    for(int i = 0; i < g->n; i++){
        if(distance[i] == INF)
            std::cout<< "*" ;
        else std::cout << distance[i];
    }
    std::cout << std::endl;
    
    std::cout << "    found:    " ;
    for (int i = 0; i < g->n; i++)
        std::cout << found[i] << " ";
    std::cout << std::endl;
}

void Dijkstra(GraphType* g, int start) {
    int n = g->n;
    distance.resize(n, INF);
    found.resize(n, false);
    
    distance[start] = 0;

    for (int i = 0; i < n; i++) {
        print_status(g);
        int u = choose(distance, n, found);
        found[u] = true;

        for (int w = 0; w < n; w++) {
            if (!found[w] && distance[u] != INF && g->weight[u][w] != INF) {
                int new_dist = distance[u] + g->weight[u][w];
                if (new_dist < distance[w]) {
                    distance[w] = new_dist;
                }
            }
        }
    }
}



int main() {
    GraphType g = {
        7,
        {
            {0, 7, INF, INF, 3, 10, INF},
            {7, 0, 4, 10, 2, 6, INF},
            {INF, 4, 0, 2, INF, INF, INF},
            {INF, 10, 2, 0, 11, 9, 4},
            {3, 2, INF, 11, 0, INF, 5},
            {10, 6, INF, 9, INF, 0, INF},
            {INF, INF, INF, 4, 5, INF, 0}
        }
    };

    Dijkstra(&g, 0);
    

    return 0;
}
