#include <iostream>
#include <valarray>

#include "multiply/multiply.h"
#include "sorts/sorts.h"
#include "dpf/dpf.h"

class Exception {};

void CommonConvolutionImpl(const vector<double>& shortSample, const vector<double>& longSample, size_t offset, vector<double>& result)
{
    if (shortSample.empty())  {
        throw Exception();
    }
    const size_t shortSize = shortSample.size();
    const size_t longSize = longSample.size();
    result = vector<double>(longSize, .0);
    for (size_t i = 0; i < longSize; ++i) {
        const size_t resultIndex = (i + longSize - offset) % longSize;
        for (size_t j = 0; j < shortSize; ++j) {
            const size_t longIndex = (i + longSize - j) % longSize;
            result[resultIndex] += shortSample[j] * longSample[longIndex];
        }
    }
}

void CommonConvolution(const vector<double>& sampleOne, vector<double>& sampleTwo, size_t offset, vector<double>& result)
{
    if (sampleOne.size() <= sampleTwo.size()) {
        return CommonConvolutionImpl(sampleOne, sampleTwo, offset, result);
    }
    else {
        return CommonConvolutionImpl(sampleTwo, sampleOne, offset, result);
    }
}

int main() {
/*    vector<double> x(10, 2.0);
    vector<double> y(10, 2.0);
    vector<double> result;
    CommonConvolution(x, y, x.size() / 2, result);
    for (auto& i: result) {
        cout << i << "\n";
    }
    return 0;*/
/*    vector<int> test {8, 9, 9, 1, 0};
    vector<int> test2 {8, 9, 9, 1};
    vector<int> result = sum(test, test2);
    for (auto& i: result) {
        cout << i;
    }*/
    do_multiply();
}
