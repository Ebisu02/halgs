//
// Created by hello on 11.11.2022.
//

#include "common_convolution.h"

long int opss = 0;

vector<int> convolution(vector<int> a, vector<int> b) {
    vector<int> res(a.size() + b.size() - 1, 0);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < a.size(); ++j) {
            for (int k = 0; k < b.size(); ++k) {
                if (j + k == i) {
                    opss += 2;
                    res[i] += a[j] * b[k];
                }
            }
        }
    }
    return res;
}

void do_convolution_common() {
    vector<int> a {1, 2};
    vector<int> b {3, 4, 5, 6};
    opss = 0;
    cout << "\nFirst array:\n";
    for (vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\nSecond array:\n";
    for (vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\nConvolution:\n";
    vector<int> res = convolution(a, b);
    for (vector<int>::iterator it = res.begin(); it != res.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\nOperations = " << opss << "\n";
}