//
// Created by hello on 21.10.2022.
//

#include "ford_bellman.h"

const int INF = 1000000000;

void search_ford_bellman(vector<Edge> edges, int n, int m, int start_vertex) {
// Step 1: Initialize distances from src to all other vertices
// as INFINITE
    vector<int> d(n, INF);
    d[start_vertex] = 0;
// Step 2: Relax all edges |V| - 1 times. A simple shortest
// path from src to any other vertex can have at-most |V| - 1
// edges
// Update dist value and parent index of the adjacent vertices of
// the picked vertex. Consider only those vertices which are still in
// queue
// Step 3: check for negative-weight cycles. The above step
// guarantees shortest distances if graph doesn't contain
// negative weight cycle. If we get a shorter path, then there
// is a cycle.
    for (;;) {
        bool any = false;
        for (int j = 0; j < m; ++j) {
            if (d[edges[j].get_next()] < INF) {
                if (d[edges[j].get_prev()] > d[edges[j].get_next()] + edges[j].get_cost()) {
                    d[edges[j].get_prev()] = d[edges[j].get_next()] + edges[j].get_cost();
                    any = true;
                }
            }
        }
        if (!any) {
            break;
        }
    }
}
