//
// Created by hello on 16.11.2022.
//

#include "convolution_dpf.h"

long int o1 = 0;

ComplexNumber to_normal(double base, double power) {
    return ComplexNumber(cos(power) * base, sin(power) * base);
}

vector<ComplexNumber> from_int_to_complex(vector<int> v) {
    vector<ComplexNumber> res;
    vector<ComplexNumber> temp;
    for (size_t i = 0; i < v.size(); ++i) {
        // ops
        o1 += 1;
        res.push_back(ComplexNumber(0.0, 0.0));
        temp.push_back(to_normal(v[i], 0));
    }
    for (size_t it = 0; it < v.size(); ++it) {
        for (size_t itn = 0; itn < v.size(); ++itn) {
            // ops
            o1 += 5;
            ComplexNumber x = ComplexNumber(cos((2 * pi * it * itn) / v.size()), -sin((2 * pi * it * itn) / v.size()));
            res[it] = res[it] + (temp[itn] * x);
        }
    }
    return res;
}

vector<ComplexNumber> convolution_fast_dpf (vector<int> a, vector<int> b) {
    size_t size = a.size() + b.size() - 1;
    while (b.size() != size) {
        b.push_back(0);
    }
    while (a.size() != size) {
        a.push_back(0);
    }
    vector<ComplexNumber> res;
    for (size_t i = 0; i < a.size(); ++i) {
        res.push_back(ComplexNumber(0.0, 0.0));
    }
    vector<ComplexNumber> c_a = from_int_to_complex(a);
    vector<ComplexNumber> c_b = from_int_to_complex(b);
    for (int i = 0; i < c_a.size(); ++i) {
        o1 += 2;
        res[i] = c_a[i] * c_b[i];
    }
    res = inverse_dpf(res);
    return res;
}

void do_convolution_dpf() {
    o1 = 0;
    vector<int> a {1, 2};
    vector<int> b {3, 4, 5, 6};
    vector<ComplexNumber> res;
    res = convolution_fast_dpf(a, b);
    cout << "\nConvolution DPF:\n";
    for (auto& i: res) {
        i.print();
    }
    cout << "\nOperations = " << o1 << "\n";
}