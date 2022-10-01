//
// Created by hello on 27.09.2022.
//

#include "sorts.h"

void bubbleSort(int* arr, int size) {
    int M = 0; int C = 0;
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++) {
            ++C;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                M+=3;
            }
        }
    std::cout << "\nPrisvaivania - " << M << "\nSravnenia - " << C << "\nSumma - " << C + M << "\n";
    return;
}

void selectSort(int* arr, int size) {
    int M = 0, C = 0;
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            ++C;
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            M+=3;
            swap(arr[i], arr[min]);
        }
    }
    std::cout << "\nPrisvaivania - " << M << "\nSravnenia - " << C << "\nSumma - " << C + M << "\n";
    return;
}

void print(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

template <class T>
T* merge(T *m1, T* m2, int l1, int l2, int& C, int& M) {
    T* ret = new T[l1 + l2];
    int n = 0;
    while (l1 && l2) {
        ++C;
        if (*m1 < *m2) {
            M += 1;
            ret[n] = *m1;
            m1++;
            l1--;
        }
        else {
            M += 1;
            ret[n] = *m2;
            m2++;
            l2--;
        }
        //    print(ret, l1 + l2);
        n++;
    }
    if (l1 == 0) {
        for (int i = 0; i < l2; ++i) {
            ++M;
            ret[n++] = *m2++;
        }
    }
    else {
        for (int i = 0; i < l1; ++i) {
            ++M;
            ret[n++] = *m1++;
        }
    }
    //  print(ret, l1 + l2);
    return ret;
}

template <class T>
void merge_sort(T *arr, int size) {
    int n = 1, l, end;
    int C = 0, M = 0;
    T* arrTemp;
    while (n < size) {
        l = 0;
        while (l < size) {
            if (l + n >= size) {
                break;
            }
            end = (l + n * 2 > size) ? (size - (l + n)) : n;
            arrTemp = merge(arr + l, arr + l + n, n, end, C, M);
            print(arrTemp, n + end);
            cout << "\t%c %m: " << C << " " << M << "\n";
            for (int i = 0; i < n + end; ++i) {
                arr[l + i] = arrTemp[i];
            }
            delete [] arrTemp;
            l += n * 2;
        }
        n *= 2;
    }
    std::cout << "\nPrisvaivania - " << M << "\nSravnenia - " << C << "\nSumma - " << C + M << "\n";
}