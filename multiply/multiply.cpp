//
// Created by hello on 04.10.2022.
//

#include "multiply.h"

int ctoi(const char c) {
    if (c == '0') return 0;
    else if (c == '1') return 1;
    else if (c == '2') return 2;
    else if (c == '3') return 3;
    else if (c == '4') return 4;
    else if (c == '5') return 5;
    else if (c == '6') return 6;
    else if (c == '7') return 7;
    else if (c == '8') return 8;
    else if (c == '9') return 9;
    else return 'n';
}

vector<int> to_vector(string your_num) {
    if (your_num.length() == 0) {
        return vector<int>(0);
    }
    string::iterator its;
    vector<int> toReturn;
    for (its = your_num.begin(); its != your_num.end(); ++its) {
        int b = ctoi(*its);
        toReturn.push_back(b);
    }
    return toReturn;
}

int get_cnt_digit(const int n) {
    if (!n) {
        return 1;
    }
    ostringstream ost;
    ost << n;
    return ost.str().length();
}

int get_last_num(const int n) {
    int x = n % 10;
    return x;
}

void show(const int a) {
    cout << a;
}

vector<int> sum(vector<int> fn, vector<int> sn) {
    vector<int> result;
    size_t n = fn.size() > sn.size() ? fn.size() + 1 : sn.size() + 1;
    if (fn.size() > sn.size()) {
        while (fn.size() != sn.size()) {
            sn.insert(sn.begin(), 0);
        }
    }
    else {
        while (sn.size() != fn.size()) {
            fn.insert(fn.begin(), 0);
        }
    }
    int temp = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (get_cnt_digit(fn[i] + sn[i] + temp) == 1) {
            result.push_back(fn[i] + sn[i] + temp);
            temp = 0;
        }
        else if (get_cnt_digit(fn[i] + sn[i] + temp) == 2) {
            result.push_back(get_last_num(fn[i] + sn[i] + temp));
            temp = (fn[i] + sn[i] / 10);
        }
    }
    if (sn.size() == fn.size() == 1 && sn[0] + fn[0] >= 10) {
        result.push_back(1);
    }
    return result;
}

vector<int> multiply_on_single_num(const vector<int> big_num, const int num, const int queue) {
    vector<int> result;
    int incnt = 0;
    for (int i = big_num.size() - 1; i >= 0; --i) {
        int x = big_num[i] * num;
        int toPush;
        if (incnt == 0) {
            toPush = x % 10;
            incnt = x / 10;
        }
        else {
            toPush = (x + incnt) % 10;
            incnt = (x + incnt) / 10;
        }
        result.push_back(toPush);
    }
    if (incnt != 0) {
        result.push_back(incnt);
    }
    reverse(result.begin(), result.end());
    for (int i = 0; i < queue; ++i) {
        result.push_back(0);
    }
    return result;
}

vector<int> multiply(const vector<int> fnum, const vector<int> snum) {
    vector<int> result = multiply_on_single_num(fnum, snum[snum.size() - 1], 0);
    if (snum.size() == 1) return result;
    for (int i = snum.size() - 2, queue = 1; i >= 0; --i, ++queue) {
        vector<int> temp = multiply_on_single_num(fnum, snum[i], queue);
        result = sum(result, temp);
        reverse(result.begin(), result.end());
    }
    return result;
}

void do_multiply() {
    string fn, sn;
    vector<int> fnum, snum, result;
    vector<vector<int>> tempSums;
    cout << "Enter first num:";
    cin >> fn;
    cout << "\nEnter second num:";
    cin >> sn;
    cout << "\n";
    fnum = to_vector(fn);
    snum = to_vector(sn);
    cout << "\nResult:";
    result = multiply(fnum, snum);
    for_each(result.begin(), result.end(), show);
}
