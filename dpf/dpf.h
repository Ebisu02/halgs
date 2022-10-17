//
// Created by hello on 17.10.2022.
//

#ifndef UNTITLED_DPF_H
#define UNTITLED_DPF_H

#include <iostream>
#include <cmath>
#include <vector>

#define pi 3.1415926

using namespace std;

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

void start_test_dpf();
vector<ComplexNumber> direct_dpf(vector<ComplexNumber> arr);
vector<ComplexNumber> inverse_dpf(vector<ComplexNumber> arr);

#endif //UNTITLED_DPF_H
