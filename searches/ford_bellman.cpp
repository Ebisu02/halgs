//
// Created by hello on 21.10.2022.
//

#include "ford_bellman.h"

const int INF = 1000000000;

void search_ford_bellman(vector<Edge> edges, int n, int m, int start_vertex) {
    vector<int> d (n, INF);
    d[start_vertex] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (d[edges[j].get_prev()] != INF) {
                d[edges[j].get_next()] = min (d[edges[j].get_next()], d[edges[j].get_prev()] + edges[j].get_cost());
            }
        }
    }
    cout << "\nFord-Bellman result:\n";
    for (auto& i: d) {
        cout << i << " ";
    }
    cout << "\n";
}

void do_fbel_test() {
    vector<Edge> t;
    int n = 6;
    int m = 13;

    t.push_back(Edge(0, 0, 0));
    t.push_back(Edge(0, 1, 2));
    t.push_back(Edge(0, 2, 7));
    t.push_back(Edge(0, 3, 4));
    t.push_back(Edge(0, 4, 6));
    t.push_back(Edge(0, 5, 3));

    t.push_back(Edge(1, 0, 3));
    t.push_back(Edge(1, 1, 0));
    t.push_back(Edge(1, 2, 4));
    t.push_back(Edge(1, 3, 5));
    t.push_back(Edge(1, 4, 6));
    t.push_back(Edge(1, 5, 1));

    t.push_back(Edge(2, 0, 3));
    t.push_back(Edge(2, 1, 4));
    t.push_back(Edge(2, 2, 0));
    t.push_back(Edge(2, 3, 8));
    t.push_back(Edge(2, 4, 7));
    t.push_back(Edge(2, 5, INF));

    t.push_back(Edge(3, 0, 4));
    t.push_back(Edge(3, 1, INF));
    t.push_back(Edge(3, 2, 8));
    t.push_back(Edge(3, 3, 0));
    t.push_back(Edge(3, 4, 5));
    t.push_back(Edge(3, 5, 7));

    t.push_back(Edge(4, 0, INF));
    t.push_back(Edge(4, 1, 7));
    t.push_back(Edge(4, 2, 8));
    t.push_back(Edge(4, 3, 4));
    t.push_back(Edge(4, 4, 0));
    t.push_back(Edge(4, 5, 3));

    t.push_back(Edge(5, 0, 2));
    t.push_back(Edge(5, 1, 4));
    t.push_back(Edge(5, 2, INF));
    t.push_back(Edge(5, 3, 7));
    t.push_back(Edge(5, 4, 8));
    t.push_back(Edge(5, 5, 0));
    search_ford_bellman(t, n, m, 0);
}
