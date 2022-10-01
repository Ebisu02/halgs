#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string first_num, second_num;

void get_nums() {
    cout << "Enter first num:";
    cin >> first_num;
    cout << "Enter second num:";
    cin >> second_num;
    cout << "A: " << first_num << " x " << second_num << "\n";
}

short int ctoi(const char c) {
    if (c == '0') return 0;
    else if (c == '1') return 1;
    else if (c == '2') return 2;
    else if (c == '3') return 3;
    else if (c == '4') return 4;
    else if (c == '5') return 5;
    else if (c == '6') return 6;
    else if (c == '7') return 7;
    else if (c == '8') return 8;
    else if (c == '9') return 9;
    else return NULL;
}

vector<short int> toVector(string your_num) {
    if (your_num.length() == 0) {
        return vector<short int>(0);
    }
    string::iterator its;
    vector<short int> toReturn;
    for (its = your_num.begin(); its != your_num.end(); ++its) {
        short int b = ctoi(*its);
        toReturn.push_back(b);
    }
}

vector<short int> multiply(vector<short int> fnum, vector<short int> snum) {
    if (fnum.size() == 0 || snum.size() == 0) {
        return vector<short int>(0);
    }
    reverse(fnum.begin(), fnum.end());
    vector<short int> result(fnum.size() * snum.size());
    vector<short int>::iterator itf, its;
    for (itf = fnum.begin(); itf != fnum.end(); ++itf) {
        // TODO MULTIPLY
    }
}

int main() {
    return 0;
}
