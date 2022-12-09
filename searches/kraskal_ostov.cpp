//
// Created by hello on 10.12.2022.
//

#include "kraskal_ostov.h"

namespace min_ostov_find {
    pair<int, vector<pair<int, int>>> kraskal_find(graph g, int n, int m) {
        sort(g.begin(), g.end());
        int cost = 0;
        vector<pair<int, int>> res;
        int sum = 0;
        vector<int> tree_id (n);
        for (int i = 0; i < n; ++i) {
            tree_id[i] = i;
        }
        for (int i = 0; i < m; ++i) {
            int a = g[i].second.first,
                    b = g[i].second.second,
                    l = g[i].first;
            if (tree_id[a] != tree_id[b]) {
                cost += 1;
                res.push_back(make_pair(a, b));
                sum += l;
                int old_id = tree_id[b],
                        new_id = tree_id[a];
                for (int j = 0; j < n; ++j) {
                    if (tree_id[j] == old_id) {
                        tree_id[j] = new_id;
                    }
                }
            }
        }
        return make_pair(sum, res);
    }

    void do_kraskal_test () {
        int n = 6;
        int m = n * (n - 1) - 2;
        graph g(m); // вес - вершина 1 - вершина 2
        g[0] = make_pair(2, make_pair(0, 1));
        g[1] = make_pair(7, make_pair(0, 2));
        g[2] = make_pair(4, make_pair(0, 3));
        g[3] = make_pair(6, make_pair(0, 4));
        g[4] = make_pair(3, make_pair(0, 5));
        g[5] = make_pair(2, make_pair(1, 0));
        g[6] = make_pair(4, make_pair(1, 2));
        g[7] = make_pair(5, make_pair(1, 3));
        g[8] = make_pair(6, make_pair(1, 4));
        g[9] = make_pair(1, make_pair(1, 5));
        g[10] = make_pair(7, make_pair(2, 0));
        g[11] = make_pair(4, make_pair(2, 1));
        g[12] = make_pair(8, make_pair(2, 3));
        g[13] = make_pair(7, make_pair(2, 4));
        g[14] = make_pair(4, make_pair(3, 0));
        g[15] = make_pair(5, make_pair(3, 1));
        g[16] = make_pair(8, make_pair(3, 2));
        g[17] = make_pair(5, make_pair(3, 4));
        g[18] = make_pair(7, make_pair(3, 5));
        g[19] = make_pair(6, make_pair(4, 0));
        g[20] = make_pair(6, make_pair(4, 1));
        g[21] = make_pair(7, make_pair(4, 2));
        g[22] = make_pair(5, make_pair(4, 3));
        g[23] = make_pair(3, make_pair(4, 5));
        g[24] = make_pair(3, make_pair(5, 0));
        g[25] = make_pair(1, make_pair(5, 1));
        g[26] = make_pair(7, make_pair(5, 3));
        g[27] = make_pair(3, make_pair(5, 4));
        auto res = kraskal_find(g, n, m);
        for (auto& i: res.second) {
            cout << "{" << i.first << " - " << i.second << "}\n";
        }
        cout << "Cost: " << res.first;
    }
}