//
// Created by hello on 04.10.2022.
//

#ifndef UNTITLED_MULTIPLY_H
#define UNTITLED_MULTIPLY_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void do_multiply();
vector<int> multiply(const vector<int> fnum, const vector<int> snum);
vector<int> multiply_on_single_num(const vector<int> big_num, const int num, const int queue);
vector<int> sum(vector<int> fn, vector<int> sn);
void show(const int a);
int get_last_num(const int n);
int get_cnt_digit(const int n);
vector<int> to_vector(string your_num);
int ctoi(const char c);

#endif //UNTITLED_MULTIPLY_H
