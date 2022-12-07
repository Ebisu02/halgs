//
// Created by hello on 07.12.2022.
//

#ifndef UNTITLED_KARATSUBA_MULTIPLY_H
#define UNTITLED_KARATSUBA_MULTIPLY_H

#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include "multiply.h"

using namespace std;

typedef int digit;
typedef unsigned long int size_length;

struct long_value {
    digit *values; // array for digits (reversed)
    size_length length; // len of number
};

long_value get_number(istream& is, string msg);
void print_result(ostream& os, long_value x);
/*
 * Sum long nums
 * Num with bigger length - first arg
 * Num with lower length - second arg
 * Returning non-normalized num
 */
long_value sum(long_value a, long_value b);
/*
 * Sub second num from first num
 * Changing first num and returning link to it
 */
long_value& sub(long_value& a, long_value& b);
void normalize(long_value l);
long_value karatsuba_multiply(long_value a, long_value b);
void do_karatsuba_multiply_test();

#endif //UNTITLED_KARATSUBA_MULTIPLY_H
