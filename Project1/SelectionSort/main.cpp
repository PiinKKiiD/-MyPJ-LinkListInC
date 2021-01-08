#include <iostream>
#include <ctime>
#include <string>
using namespace std;

#include "DataGenerator.h"
#include "Sorts.h"

int main()
{
	int a[100050], size;
	int b[100050];
	int order, al = 0;
	string algor[12] = { "Selection", "Insert", "Binary-Insert", "Bubble", "Shaker" , "Shell", "Heap", "Merge", "Quick", "Counting", "Radix", "Flash" };
	for (order = 0; order < 4; order++)
	{
		size = 1000;
		switch (order)
		{
		case 0: {cout << "	**Random data." << endl << endl; break; }
		case 1: {cout << "	**Sorted data." << endl << endl; break; }
		case 2: {cout << "	**Reverse data." << endl << endl; break; }
		case 3: {cout << "	**Nearly Sorted data." << endl << endl; break; }
		}
		while (size < 100050)
		{
			cout << endl;
			cout << "**********************" << endl;
			clock_t beginCreateData = clock();
			GenerateData(b, size, order);
			clock_t endCreateData = clock();
			cout << "Time run for creat Data with the size of " << size << " : " << (float)(endCreateData - beginCreateData) * 1000 / CLOCKS_PER_SEC << " ms." << endl << endl;
			cout << endl << endl;
			al = 0;
			while (al < 12)
			{

				switch (al)
				{
				case 0:
				{
					copyData(b, a, size);
					clock_t beginSort = clock();
					selectSort(a, size);
					clock_t endSort = clock();
					cout << "Time run for " << algor[al] << "Sort with the size of " << size << " : " << (float)(endSort - beginSort) * 1000 / CLOCKS_PER_SEC << " ms." << endl<< endl;
					break;
				}
				case 1:
				{
					copyData(b, a, size);
					clock_t beginSort = clock();
					insertSort(a, size);
					clock_t endSort = clock();
					//for (int i = 0; i < 15; i++)
					//	cout << a[i] << "	";
					//cout << endl;
					cout << "Time run for " << algor[al] << "Sort with the size of " << size << " : " << (float)(endSort - beginSort) * 1000 / CLOCKS_PER_SEC << " ms." << endl << endl;
					break;
				}
				case 2:
				{
					copyData(b, a, size);
					clock_t beginSort = clock();
					binaryInsertSort(a, size);
					clock_t endSort = clock();
					cout << "Time run for " << algor[al] << "Sort with the size of " << size << " : " << (float)(endSort - beginSort) * 1000 / CLOCKS_PER_SEC << " ms." << endl << endl;
					break;
				}
				case 3:
				{
					copyData(b, a, size);
					clock_t beginSort = clock();
					bubbleSort(a, size);
					clock_t endSort = clock();
					cout << "Time run for " << algor[al] << "Sort with the size of " << size << " : " << (float)(endSort - beginSort) * 1000 / CLOCKS_PER_SEC << " ms." << endl << endl;
					break;
				}
				case 4:
				{
					copyData(b, a, size);
					clock_t beginSort = clock();
					shakeSort(a, size);
					clock_t endSort = clock();
					cout << "Time run for " << algor[al] << "Sort with the size of " << size << " : " << (float)(endSort - beginSort) * 1000 / CLOCKS_PER_SEC << " ms." << endl << endl;
					break;
				}
				case 5:
				{

					copyData(b, a, size);
					clock_t beginSort = clock();
					shellSort(a, size);
					clock_t endSort = clock();
					cout << "Time run for " << algor[al] << "Sort with the size of " << size << " : " << (float)(endSort - beginSort) * 1000 / CLOCKS_PER_SEC << " ms." << endl << endl;
					break;
				}
				case 6:
				{
					copyData(b, a, size);
					clock_t beginSort = clock();
					heapSort(a, size);
					clock_t endSort = clock();
					cout << "Time run for " << algor[al] << "Sort with the size of " << size << " : " << (float)(endSort - beginSort) * 1000 / CLOCKS_PER_SEC << " ms." << endl << endl;
					/*for (int i = 0; i < 15; i++)
						cout << a[i] << "	";*/
					break;
				}
				case 7:
				{
					//It is ok.
					copyData(b, a, size);
					clock_t beginSort = clock();
					mergeSort(a, 0, size - 1);
					clock_t endSort = clock();
					cout << "Time run for " << algor[al] << "Sort with the size of " << size << " : " << (float)(endSort - beginSort) * 1000 / CLOCKS_PER_SEC << " ms." << endl << endl;
					/*for (int i = 0; i < 15; i++)
						cout << a[i] << "	";*/
					break;
				}
				case 8:
				{
					
					copyData(b, a, size);
					clock_t beginSort = clock();
					quickSort(a, 0, size - 1);
					clock_t endSort = clock();
					cout << "Time run for " << algor[al] << "Sort with the size of " << size << " : " << (float)(endSort - beginSort) * 1000 / CLOCKS_PER_SEC << " ms." << endl << endl;
					/*for (int i = 0; i < 15; i++)
						cout << a[i] << "	";*/
					break;
				}
				case 9:
				{
					////Its ok
					copyData(b, a, size);
					clock_t beginSort = clock();
					countingSort(a, size);
					clock_t endSort = clock();
					cout << "Time run for " << algor[al] << "Sort with the size of " << size << " : " << (float)(endSort - beginSort) * 1000 / CLOCKS_PER_SEC << " ms." << endl << endl;
					//for (int i = 0; i < 15; i++)
					//	cout << a[i] << "	";
					//cout << endl;

					break;
				}
				case 10:
				{
					//It is ok.
					copyData(b, a, size);
					clock_t beginSort = clock();
					radixSort(a, size);
					clock_t endSort = clock();
					cout << "Time run for " << algor[al] << "Sort with the size of " << size << " : " << (float)(endSort - beginSort) * 1000 / CLOCKS_PER_SEC << " ms." << endl << endl;
					/*for (int i = 0; i < 15; i++)
						cout << a[i] << "	";*/
					break;
				}
				case 11:
				{
					//It is ok.
					copyData(b, a, size);
					clock_t beginSort = clock();
					flashSort(a, size);
					clock_t endSort = clock();
					cout << "Time run for " << algor[al] << "Sort with the size of " << size << " : " << (float)(endSort - beginSort) * 1000 / CLOCKS_PER_SEC << " ms." << endl << endl;
					//for (int i = 0; i < 15; i++)
					//	cout << a[i] << "	";
					//cout << endl;
					break;
				}

				}
				al += 1;
			}
			
			/*for (int i = 0; i < 100; i++)
				cout << a[i] << "	";*/
			cout << endl << endl;
			switch (size)
			{
			case 1000: {size = 3000; break; }
			case 3000: {size = 10000; break; }
			case 10000: {size = 30000; break; }
			case 30000: {size = 100000; break; }
			case 100000: {size = 1000000; break; }
			}
		}
		cout << endl << endl << "*8*8*8*8*8*8*8*8*8*8*8*8*8*8*8" << endl;
	}
	
	system("pause");
	return 0;
}