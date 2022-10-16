#include <iostream>
#include <valarray>

#include "multiply/multiply.h"
#include "sorts/sorts.h"

#define pi 3.1415926

class ComplexNumber {

private:
    long double Real;
    long double Image;

public:
    ComplexNumber(long double RealPart, long double ImagePart) {
        this->Real = RealPart;
        this->Image = ImagePart;
    }

    void print() {
        if (this->get_image() > 0) {
            cout << this->get_real() << " + " << this->get_image() << "i ";
        }
        else if (this->get_image() < 0) {
            cout << this->get_real() << " " << this->get_image() << "i ";
        }
        else {
            cout << this->get_real() << " ";
        }
    }

    long double get_real() {
        return this->Real;
    }

    long double get_image() {
        return this->Image;
    }

    ComplexNumber operator + (ComplexNumber other) {
        return ComplexNumber(this->get_real() + other.get_real(), this->get_image() + other.get_image());
    }

    ComplexNumber operator - (ComplexNumber other) {
        return ComplexNumber(this->get_real() - other.get_real(), this->get_image() - other.get_image());
    }

    ComplexNumber operator * (ComplexNumber other) {
        long double new_real = this->get_real() * other.get_real() - this->get_image() * other.get_image();
        long double new_image = this->get_real() * other.get_image() + this->get_image() * other.get_real();
        return ComplexNumber(new_real, new_image);
    }

    ComplexNumber operator / (ComplexNumber other) {
        long double new_real = (long double)(this->get_real() * other.get_real() + this->get_image() * other.get_image()) / (pow(other.get_real(), 2) + pow(other.get_image(), 2));
        long double new_image = (long double)(this->get_image() * other.get_real() - this->get_real() * other.get_image()) / (pow(other.get_real(), 2) + pow(other.get_image(), 2));
        return ComplexNumber(new_real, new_image);
    }

    void Round(long int n) {
        this->Real = (round(Real * 1000)) / 1000;
        this->Image = (round(Image * 1000)) / 1000;
    }
};

long int operations;

vector<ComplexNumber> direct(vector<ComplexNumber> arr) {
    operations = 0;
    vector<ComplexNumber> result_arr;
    for (size_t i = 0; i < arr.size(); ++i) {
        result_arr.push_back(ComplexNumber(0.0, 0.0));
    }
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t n = 0; n < arr.size(); ++n) {
            operations += 5;
            ComplexNumber temp = ComplexNumber(cos((2 * pi * i * n) / arr.size()),
                                               -1 * sin((2 * pi * i * n) / arr.size()));
            result_arr[i] = result_arr[i] + (arr[n] * temp);
        }
        result_arr[i].Round(3);
    }
    return result_arr;
}

vector<ComplexNumber> inverse(vector<ComplexNumber> arr) {
    operations = 0;
    vector<ComplexNumber> result_arr;
    for (size_t i = 0; i < arr.size(); ++i) {
        result_arr.push_back(ComplexNumber(0.0, 0.0));
    }
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t n = 0; n < arr.size(); ++n) {
            operations += 5;
            ComplexNumber temp = ComplexNumber(cos((2 * pi * i * n) / arr.size()), sin((2 * pi * i * n) / arr.size()));
            result_arr[i] = result_arr[i] + (arr[n] * temp);
        }
        result_arr[i] = result_arr[i] / ComplexNumber(arr.size(), 0);
        result_arr[i].Round(3);
    }
    return result_arr;
}

void test() {
    vector<ComplexNumber> t;
    t.push_back(ComplexNumber(1, 0));
    t.push_back(ComplexNumber(2, -1));
    t.push_back(ComplexNumber(0, -1));
    t.push_back(ComplexNumber(-1, 2));

    cout << "Array: \n";
    for (auto& i: t) {
        i.print();
        cout << "\n";
    }

    vector<ComplexNumber> dir;
    dir = direct(t);

    cout << "Array after direct: \n";
    for (auto& i: dir) {
        i.print();
        cout << "\n";
    }
    cout << "Operations: " << operations << "\n";

    vector<ComplexNumber> inv;
    inv = inverse(dir);
    cout << "Array after inverse: \n";
    for (auto& i: inv) {
        i.print();
        cout << "\n";
    }
    cout << "Operations: " << operations << "\n";
}

int main() {
    test();
    return 0;
}
