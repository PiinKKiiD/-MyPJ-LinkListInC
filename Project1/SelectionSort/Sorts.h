#pragma once

void selectSort(int a[], int n);
void insertSort(int a[], int n);
void binaryInsertSort(int a[], int n);
void bubbleSort(int a[], int n);
void shakeSort(int a[], int n);
void shellSort(int a[], int n);
void heapSort(int a[], int n);
void heapify(int a[], int n); //be used in heap sort
void merge(int a[], int left, int mid, int right);	//be used in merge sort
void mergeSort(int a[], int l, int r);
void quickSort(int a[], int low, int high);
void countingSort(int a[],int n);
int getMax(int a[], int n);	//be used in RadixSort
void countSort(int a[], int n, int exp);	//be used in Radix Sort
void radixSort(int a[], int n);
int digit(int a, int k);
void sort(int a[], int n, int k);	//be used in Radix sort
void flashSort(int a[], int n);