cmake_minimum_required(VERSION 3.22.3)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp sorts/sorts.cpp sorts/sorts.h multiply/multiply.cpp multiply/multiply.h dpf/dpf.cpp dpf/dpf.h searches/ford_bellman.cpp searches/ford_bellman.h convolution/common_convolution.cpp convolution/common_convolution.h convolution/convolution_dpf.cpp convolution/convolution_dpf.h backpack/backpack_problem.cpp backpack/backpack_problem.h searches/dijkstra.cpp searches/dijkstra.h multiply/karatsuba_multiply.cpp multiply/karatsuba_multiply.h multiply/strassen_fast_matrix_multiply.cpp multiply/strassen_fast_matrix_multiply.h searches/kraskal_ostov.cpp searches/kraskal_ostov.h)
