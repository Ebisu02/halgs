#include <iostream>
#include <valarray>

#include "multiply/multiply.h"
#include "sorts/sorts.h"
#include "dpf/dpf.h"
#include "convolution/common_convolution.h"
#include "convolution/convolution_dpf.h"

int main() {
    do_convolution_common();
    do_convolution_dpf();
}
