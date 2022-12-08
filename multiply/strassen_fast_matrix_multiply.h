//
// Created by hello on 09.12.2022.
//

#ifndef UNTITLED_STRASSEN_FAST_MATRIX_MULTIPLY_H
#define UNTITLED_STRASSEN_FAST_MATRIX_MULTIPLY_H

#include <iostream>
#include <assert.h>

using namespace std;

namespace fast_matrix_multiply {
    const int M = 2;
    const int N = 1 << M;
    typedef double datatype;
    typedef datatype mat[N][N];

    typedef struct {
        int ra, rb, ca, cb;
    } corners;

    void identity(mat A, corners a);
    void set(mat A, corners a, datatype k);
    void randk(mat A, corners a, datatype l, datatype h);
    void print(mat A, corners a, string msg);
    void add(mat A, mat B, mat &C, corners a, corners b, corners c);
    void sub(mat A, mat B, mat C, corners a, corners b, corners c);
    void find_corner(corners a, int i, int j, corners *b);
    void mul(mat A, mat B, mat &C, corners a, corners b, corners c);
    void multiply_matrix_native(mat A, mat B, mat &C, corners a, corners b, corners c);
    void do_multiply_stresson_test();
}

#endif //UNTITLED_STRASSEN_FAST_MATRIX_MULTIPLY_H
