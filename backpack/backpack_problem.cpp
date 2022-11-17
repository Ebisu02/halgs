//
// Created by hello on 17.11.2022.
//

#include "backpack_problem.h"

int BACKPACK_CAPACITY = 10;

vector<pair<int, int>> loot = { {1, 1}, {2, 4}, {3, 6}, {4, 8} };
vector<int> result_loot(BACKPACK_CAPACITY + 1, 0);

int get_min_weight() {
    int min_weight = INT_MAX;
    for (vector<pair<int, int>>::iterator it = loot.begin(); it != loot.end(); ++it) {
        if ((*it).first < min_weight) {
            min_weight = (*it).first;
        }
    }
    return min_weight;
}

int choose_loot(int x) {
    vector<int> temp;
    if (x >= get_min_weight()) {
        temp.push_back(0);
        int answer = 0;
        int sum = 0;
        for (vector<pair<int, int>>::iterator it = loot.begin(); it != loot.end(); ++it) {
            if (x - (*it).first >= 0) {
                if (result_loot[x - (*it).first] < 0) {
                    sum = -1 * INT_MAX;
                }
                else {
                    sum = result_loot[x - (*it).first];
                }
            }
            else {
                sum = -1 * INT_MAX;
            }
            temp.push_back(sum + (*it).second);
        }
        for (vector<int>::iterator ita = temp.begin(); ita != temp.end(); ++ita) {
            answer = max(answer, *ita);
        }
        int index = 0;
        vector<int>::iterator itbb = find(temp.begin(), temp.end(), answer);
        if (itbb != temp.end()) {
            index = distance(temp.begin(), itbb);
        }
        if (x == BACKPACK_CAPACITY) {
            vector<int> prod_count(loot.size(), 0);
            int i = x;
            while (i > 0) {
                int max_cost = 0;
                int max_ind = -1;
                for (vector<pair<int, int>>::iterator itn = loot.begin(); itn != loot.end(); ++itn) {
                    if (i - (*itn).first < 0) {
                        continue;
                    }
                    else if (result_loot[i - (*itn).first] + (*itn).second > max_cost) {
                        max_cost = result_loot[i - (*itn).first] + (*itn).second;
                        max_ind = distance(loot.begin(), itn);
                    }
                }
                if (max_ind == -1) {
                    break;
                }
                prod_count[max_ind] += 1;
                i -= loot[max_ind].first;
            }
            int res_weight = 0;
            int j = 0;
            for (vector<pair<int, int>>::iterator itc = loot.begin(); itc != loot.end(); ++itc, ++j) {
                cout << "Count of loot with weight = " << (*itc).first << ": " << prod_count[j] <<
                     " (their summary cost: " << prod_count[j] * (*itc).second << ")\n";
                res_weight += prod_count[j] * (*itc).first;
            }
            cout << "Result weight of the backpack: " << res_weight << "\n";
        }
        return answer;
    }
    return 0;
}

void do_backpack_test() {
    int i = 0;
    for (vector<int>::iterator it = result_loot.begin(); it != result_loot.end(); ++it, ++i) {
        *it = choose_loot(i);
    }
    cout << "Result cost of backpack: " << result_loot[result_loot.size() - 1] << "\n";
}