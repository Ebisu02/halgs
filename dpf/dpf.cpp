//
// Created by hello on 17.10.2022.
//

#include "dpf.h"

long int operations = 0;

vector<ComplexNumber> direct_dpf(vector<ComplexNumber> arr) {
    operations = 0;
    vector<ComplexNumber> result_arr;
    for (size_t i = 0; i < arr.size(); ++i) {
        result_arr.push_back(ComplexNumber(0.0, 0.0));
    }
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t n = 0; n < arr.size(); ++n) {
            operations += 5;
            ComplexNumber temp = ComplexNumber(cos((2 * pi * i * n) / arr.size()),
                                               -1 * sin((2 * pi * i * n) / arr.size()));
            cout << "\n\nTemp = ";
            temp.print();
            cout << "\n\nRes = ";
            result_arr[i] = result_arr[i] + (arr[n] * temp);
            result_arr[i].print();
        }
        cout <<"\n\nNExt:\n\n";
        result_arr[i].Round(3);
    }
    return result_arr;
}

vector<ComplexNumber> inverse_dpf(vector<ComplexNumber> arr) {
    operations = 0;
    vector<ComplexNumber> result_arr;
    for (size_t i = 0; i < arr.size(); ++i) {
        result_arr.push_back(ComplexNumber(0.0, 0.0));
    }
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t n = 0; n < arr.size(); ++n) {
            operations += 5;
            ComplexNumber temp = ComplexNumber(cos((2 * pi * i * n) / arr.size()), sin((2 * pi * i * n) / arr.size()));
            result_arr[i] = result_arr[i] + (arr[n] * temp);
        }
        result_arr[i] = result_arr[i] / ComplexNumber(arr.size(), 0);
        result_arr[i].Round(3);
    }
    return result_arr;
}

void start_test_dpf() {
    vector<ComplexNumber> t;
    t.push_back(ComplexNumber(1, 0));
    t.push_back(ComplexNumber(0, 0));
    t.push_back(ComplexNumber(2, 0));
    t.push_back(ComplexNumber(0, 0));
    t.push_back(ComplexNumber(3, 0));

    cout << "Array: \n";
    for (auto& i: t) {
        i.print();
        cout << "\n";
    }

    vector<ComplexNumber> dir;
    dir = direct_dpf(t);

    cout << "Array after direct_dpf: \n";
    for (auto& i: dir) {
        i.print();
        cout << "\n";
    }
    cout << "Operations: " << operations << "\n";

    vector<ComplexNumber> inv;
    inv = inverse_dpf(dir);
    cout << "Array after inverse_dpf: \n";
    for (auto& i: inv) {
        i.print();
        cout << "\n";
    }
    cout << "Operations: " << operations << "\n";
}
