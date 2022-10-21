//
// Created by hello on 21.10.2022.
//

#include "ford_bellman.h"

const int INF = 1000000000;

void search_ford_bellman(vector<Edge> edges, int n, int m, int start_vertex) {
    vector<int> d(n, INF);
    d[start_vertex] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (d[edges[j].get_next()] < INF) {
                d[edges[j].get_prev()] = min (d[edges[j].get_prev()], d[edges[j].get_next() + edges[j].get_cost()]);
            }
        }
    }
}
