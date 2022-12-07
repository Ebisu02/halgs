//
// Created by hello on 07.12.2022.
//

#include "dijkstra.h"

const int INF = INT_MAX;

vector<int> dikstra_find(vector<int> d, int n, int begin_index) {
    int** links = new int*[n];
    for (int i = 0; i < n; ++i) {
        links[i] = new int[n];
    }
    for (int i = 0; i < n * n; ++i) {
        links[i / n][i % n] = d[i];
    }
    vector<int> min_dist(n);
    vector<int> visited(n);
    // на вход - матрица связей
    int temp, min_index, min;
    for (int i = 0; i < n; ++i) {
        min_dist[i] = INT_MAX;
        visited[i] = 1;
    }
    min_dist[begin_index] = 0;
    // алгоритм
    do {
        min_index = INT_MAX;
        min = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if ((visited[i] == 1) && (min_dist[i] < min)) {
                min = min_dist[i];
                min_index = i;
            }
        }
        if (min_index != INT_MAX) {
            for (int i = 0; i < n; ++i) {
                if (links[min_index][i] > 0) {
                    temp = min + links[min_index][i];
                    if (temp < min_dist[i]) {
                        min_dist[i] = temp;
                    }
                }
            }
            visited[min_index] = 0;
        }
    } while (min_index < INT_MAX);
    return min_dist;
}

void do_dikstra_test() {
    int n = 6;
    vector<int> links = {0, 2, 7, 4, 6, 3,
                         3, 0, 4, 5, 6, 1,
                         2, 4, 0, 8, 7, 0,
                         4, 0, 8, 0, 5, 7,
                         0, 7, 8, 4, 0, 3,
                         2, 4, 0, 7, 8, 0};
    int begin_index = 0;
    vector<int> min_dist = dikstra_find(links, n, begin_index);
    // Вывод кратчайших расстояний от вершина begin_index до всех остальных
    cout << "\nDijkstra result\n";
    for (int i = 0; i < n; ++i) {
        cout << min_dist[i] << " ";
    }
    cout << "\n";
}