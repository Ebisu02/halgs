//
// Created by hello on 27.09.2022.
//

#ifndef UNTITLED_SORTS_H
#define UNTITLED_SORTS_H

#include <iostream>

using namespace std;

void bubbleSort(int* arr, int size);

void selectSort(int* arr, int size);

void print(int* arr, int size);

template<typename T>
void merge_sort(T *arr, int size);

template <class T>
T* merge(T *m1, T* m2, int l1, int l2, int& C, int& M);

#endif //UNTITLED_SORTS_H
