//
// Created by hello on 07.12.2022.
//

#include "karatsuba_multiply.h"

const int BASE = 10;
const int MIN_LENGTH_FOR_KARATSUBA = 4;

long_value get_number(istream& is, string msg) {
    string your_num;
    cout << msg;
    is >> your_num;
    cout << "\n";
    if (your_num.length() == 0) {
        throw "String for number is empty";
    }
    long_value toReturn;
    toReturn.values = new digit[your_num.size()];
    toReturn.length = your_num.size();
    int i = 0;
    for (auto its = your_num.crbegin(); its != your_num.crend(); ++its, ++i) {
        toReturn.values[i] = ctoi(*its);
    }
    return toReturn;
}

void print_result(ostream& os, long_value x) {
    cout << "Result: ";
    if (x.values[x.length - 1] != 0) {
        os << x.values[x.length - 1];
    }
    for (size_t i = x.length - 2; i > 0; --i) {
        os << x.values[i];
    }
    os << x.values[0];
    os << "\n";
}

// Sum long nums
// Num with bigger length - first arg
// Num with lower length - second arg
// Returning non-normalized num
long_value sum(long_value a, long_value b) {
    long_value s;
    s.length = a.length + 1;
    s.values = new digit[s.length];
    s.values[a.length - 1] = a.values[a.length - 1];
    s.values[a.length] = 0;
    for (size_length i = 0; i < b.length; ++i) {
        s.values[i] = a.values[i] + b.values[i];
    }
    return s;
}

// Sub second num from first num
// Changing first num and returning link to it
long_value& sub(long_value& a, long_value& b) {
    for (size_length i = 0; i < b.length; ++i) {
        a.values[i] -= b.values[i];
    }
    return a;
}

void normalize(long_value l) {
    for (size_length i = 0; i < l.length - 1; ++i) {
        // If bigger - carry over
        if (l.values[i] >= BASE) {
            digit carryover = l.values[i] / BASE;
            l.values[i + 1] += carryover;
            l.values[i] -= carryover * BASE;
        }
            // If lower - loan
        else if (l.values[i] < 0) {
            digit carryover = (l.values[i] + 1) / BASE - 1;
            l.values[i + 1] += carryover;
            l.values[i] -= carryover * BASE;
        }
    }
}

long_value karatsuba_multiply(long_value a, long_value b) {
    long_value product;
    product.length = a.length + b.length;
    product.values = new digit[product.length];
    // Naive Method
    if (a.length < MIN_LENGTH_FOR_KARATSUBA) {
        memset(product.values, 0, sizeof(digit) * product.length);
        for (size_length i = 0; i < a.length; ++i) {
            for (size_length j = 0; j < b.length; ++j) {
                product.values[i + j] += a.values[i] * b.values[j];
            }
        }
    }
        // Karatsuba Method
    else {
        // Young part
        long_value a_part1;
        a_part1.values = a.values;
        a_part1.length = (a.length + 1) / 2;
        // Old part
        long_value a_part2;
        a_part2.values = a.values + a_part1.length;
        a_part2.length = a.length / 2;

        // Young part
        long_value b_part1;
        b_part1.values = b.values;
        b_part1.length = (b.length + 1) / 2;
        // Old part
        long_value b_part2;
        b_part2.values = b.values + b_part1.length;
        b_part2.length = b.length / 2;

        long_value sum_of_a_parts = sum(a_part1, a_part2);
        normalize(sum_of_a_parts);
        long_value sum_of_b_parts = sum(b_part1, b_part2);
        normalize(sum_of_b_parts);

        // Result of multiply parts
        long_value product_of_sums_of_parts = karatsuba_multiply(sum_of_b_parts, sum_of_b_parts);
        // Young
        long_value product_of_first_parts = karatsuba_multiply(a_part1, b_part1);
        // Old
        long_value product_of_second_parts = karatsuba_multiply(a_part2, b_part2);
        // Sum for middle digits
        long_value sum_of_middle_terms = sub(sub(product_of_sums_of_parts, product_of_first_parts), product_of_second_parts);

        // Sum
        memcpy(product.values, product_of_first_parts.values, product_of_first_parts.length * sizeof(digit));
        memcpy(product.values + product_of_first_parts.length, product_of_second_parts.values, product_of_second_parts.length * sizeof(digit));
        for (size_length i = 0; i < sum_of_middle_terms.length; ++i) {
            product.values[a_part1.length + i] += sum_of_middle_terms.values[i];
        }

        delete[] sum_of_a_parts.values;
        delete[] sum_of_b_parts.values;
        delete[] product_of_sums_of_parts.values;
        delete[] product_of_first_parts.values;
        delete[] product_of_second_parts.values;
    }
    normalize(product);
    return product;
}

void do_karatsuba_multiply_test() {
    long_value x = get_number(cin, "Enter: ");
    long_value y = get_number(cin, "Enter: ");
    long_value z = karatsuba_multiply(x, y);
    print_result(cout, z);
}