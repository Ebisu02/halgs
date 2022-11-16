//
// Created by hello on 16.11.2022.
//

#ifndef UNTITLED_CONVOLUTION_DPF_H
#define UNTITLED_CONVOLUTION_DPF_H

#include "../dpf/dpf.h"

ComplexNumber to_normal(double base, double power);
vector<ComplexNumber> from_int_to_complex(vector<int> v);
vector<ComplexNumber> convolution_fast_dpf (vector<int> a, vector<int> b);
void do_convolution_dpf();

#endif //UNTITLED_CONVOLUTION_DPF_H
