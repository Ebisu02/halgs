#include "multiply/multiply.h"
#include "sorts/sorts.h"
#include "dpf/dpf.h"
#include "convolution/common_convolution.h"
#include "convolution/convolution_dpf.h"
#include "backpack/backpack_problem.h"
#include "searches/ford_bellman.h"
#include "searches/dijkstra.h"
#include "multiply/karatsuba_multiply.h"
#include "multiply/strassen_fast_matrix_multiply.h"

int main() {
    //do_karatsuba_multiply_test();
    fast_matrix_multiply::do_multiply_stresson_test();
}
