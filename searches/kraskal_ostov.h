//
// Created by hello on 10.12.2022.
//

#ifndef UNTITLED_KRASKAL_OSTOV_H
#define UNTITLED_KRASKAL_OSTOV_H

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

namespace min_ostov_find {
    typedef vector<pair<int, pair<int, int>>> graph;

    pair<int, vector<pair<int, int>>> kraskal_find(graph g, int n, int m);
    void do_kraskal_test();
}

#endif //UNTITLED_KRASKAL_OSTOV_H
