#include <iostream>
#include <valarray>

#include "multiply/multiply.h"
#include "sorts/sorts.h"

class ComplexNum {
private:
    long double ImagePart = 0;
    long double RealPart = 0;
public:
    ComplexNum(long double real, long double img) {
        this->ImagePart = img;
        this->RealPart = real;
    }

    string get_as_string() {
        return (to_string(RealPart) + " " + to_string(ImagePart) + "i");
    }

    long double get_image() {
        return this->ImagePart;
    }
    long double get_real() {
        return this->RealPart;
    }

    static ComplexNum add(ComplexNum c1, ComplexNum c2) {
        return ComplexNum(c1.get_real() + c2.get_real(), c1.get_image() + c2.get_image());
    }

    static ComplexNum dif(ComplexNum c1, ComplexNum c2) {
        return ComplexNum(c1.get_real() - c2.get_real(), c1.get_image() - c2.get_image());
    }

    static ComplexNum multiply(ComplexNum c1, ComplexNum c2) {
        long double new_real = c1.get_real() * c2.get_real() - c1.get_image() * c2.get_image();
        long double new_image = c1.get_real() * c2.get_image() + c1.get_image() * c2.get_real();
        return ComplexNum(new_real, new_image);
    }

    static ComplexNum div(ComplexNum c1, ComplexNum c2) {
        long double new_real = (c1.get_real() * c2.get_real() + c1.get_image() * c2.get_image()) /
                (pow(c2.get_real(), 2) + pow(c2.get_image(), 2));
        long double new_image = c1.get_image() * c2.get_real() - c1.get_real() * c2.get_image() /
                (pow(c2.get_real(), 2) + pow(c2.get_image(), 2));
        return ComplexNum(new_real, new_image);
    }
};

int operations = 0;

#define pi 3.1415926

vector<ComplexNum> direct_dpf(vector<ComplexNum> init) {
    vector<ComplexNum> result;
    operations = 0;
    for (int i = 0; i < init.size(); ++i) {
        result.push_back(ComplexNum(0.0, 0.0));
    }
    for (int i = 0; i < init.size(); ++i) {
        for (int j = 0; j < init.size(); ++j) {
            operations += 5;
            ComplexNum temp = ComplexNum(cos((2 * pi * i * j) / init.size()), -1 * sin((2 * pi * i * j) / init.size()));
            result[i] = ComplexNum::add(result[i], ComplexNum::multiply(init[j], temp));
        }
    }
    return result;
}

vector<ComplexNum> inverse_dpf(vector<ComplexNum> init) {
    vector<ComplexNum> result;
    operations = 0;
    for (int i = 0; i < init.size(); ++i) {
        result.push_back(ComplexNum(0.0, 0.0));
    }
    for (int i = 0; i < init.size(); ++i) {
        for (int j = 0; j < init.size(); ++j) {
            operations += 5;
            ComplexNum temp = ComplexNum(cos((2 * pi * i * j) / init.size()), sin((2 * pi * i * j) / init.size()));
            result[i] = ComplexNum::add(result[i], ComplexNum::multiply(init[j], temp));
        }
        result[i] = ComplexNum::div(result[i], ComplexNum(init.size(), 0));
    }
    return result;
}

bool dpf_test() {
    vector<ComplexNum> array_init;
    array_init.push_back(ComplexNum(1, 0));
    array_init.push_back(ComplexNum(2, -1));
    array_init.push_back(ComplexNum(0, -1));
    array_init.push_back(ComplexNum(-1, -2));
    cout << "\nArray:\n";
    for (vector<ComplexNum>::iterator it = array_init.begin(); it != array_init.end(); ++it) {
        cout << (*it).get_as_string() << "\n";
    }
    // Testing direct DPF algo
    vector<ComplexNum> array_direct_dpf = direct_dpf(array_init);
    cout << "\nArray after direct DPF:\n";
    for (vector<ComplexNum>::iterator it = array_direct_dpf.begin(); it != array_direct_dpf.end(); ++it) {
        cout << (*it).get_as_string() << "\n";
    }
    cout << "\nAmount of operations: " << operations << "\n";
    // Testing inverse DPF algo
    vector<ComplexNum> array_inverse_dpf = inverse_dpf(array_direct_dpf);
    cout << "\nArray after inverse DPF:\n";
    for (vector<ComplexNum>::iterator it = array_inverse_dpf.begin(); it != array_inverse_dpf.end(); ++it) {
        cout << (*it).get_as_string() << "\n";
    }
    cout << "\nAmount of operations: " << operations << "\n";
    for (vector<ComplexNum>::iterator it_init = array_init.begin(), it_inv = array_inverse_dpf.begin();
        it_init != array_init.end(), it_inv != array_inverse_dpf.end(); ++it_inv, ++it_init) {
        if ((*it_inv).get_as_string() != (*it_init).get_as_string()) {
            return false;
        }
    }
    return true;
}

int main() {
    dpf_test();
    return 0;
}
