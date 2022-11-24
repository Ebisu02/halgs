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
            if (d[edges[j].get_prev()] < INF) {
                d[edges[j].get_next()] = min (d[edges[j].get_next()], d[edges[j].get_prev()] + edges[j].get_cost());
            }
        }
    }
    cout << "\n";
    for (auto& i: d) {
        cout << i << " ";
    }
    cout << "\n";
}

void do_fbel_test() {
    vector<Edge> t;
    int n = 5;
    int m = 5;
    Edge t1(0, 1, 10), t2(1, 2, 5), t3(2, 4, 7), t4(2, 3, 1), t5(3, 4, 2);
    cout << "from: " << t1.get_prev() << " to: " << t1.get_next() << " cost: " << t1.get_cost() << "\n";
    cout << "from: " << t2.get_prev() << " to: " << t2.get_next() << " cost: " << t2.get_cost() << "\n";
    cout << "from: " << t3.get_prev() << " to: " << t3.get_next() << " cost: " << t3.get_cost() << "\n";
    cout << "from: " << t4.get_prev() << " to: " << t4.get_next() << " cost: " << t4.get_cost() << "\n";
    cout << "from: " << t5.get_prev() << " to: " << t5.get_next() << " cost: " << t5.get_cost() << "\n";
    t.push_back(t1);
    t.push_back(t2);
    t.push_back(t3);
    t.push_back(t4);
    t.push_back(t5);
    search_ford_bellman(t, n, m, 0);
}
