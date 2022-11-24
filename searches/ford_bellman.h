//
// Created by hello on 21.10.2022.
//

#ifndef UNTITLED_FORD_BELLMAN_H
#define UNTITLED_FORD_BELLMAN_H

#include <vector>
#include <iostream>

using namespace std;

class Edge {
private:
    int next = 0;
    int prev = 0;
    int cost = 0;
public:
    Edge (int prev, int next, int cost) {
        this->next = next;
        this->prev = prev;
        this->cost = cost;
    }

    int get_next() {
        return this->next;
    }

    int get_prev() {
        return this->prev;
    }

    int get_cost() {
        return this->cost;
    }

    void set_next(int x) {
        this->next = x;
    }

    void set_prev(int x) {
        this->prev = x;
    }

    void set_cost(int x) {
        this->cost = x;
    }
};

void search_ford_bellman(vector<Edge> edges, int n, int m, int start_vertex);
void do_fbel_test();

#endif //UNTITLED_FORD_BELLMAN_H
