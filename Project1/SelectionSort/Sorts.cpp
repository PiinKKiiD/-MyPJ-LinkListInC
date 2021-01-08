#include <iostream>

using namespace std;

#include "DataGenerator.h"
#include "Sorts.h"

void selectSort(int a[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		HoanVi(a[min], a[i]);
	}
}

void insertSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int current = a[i];
		int scan = i - 1;
		//Scan back until current > a[scan] or scan <0 :
		while (scan >= 0 && current < a[scan])
		{
			a[scan + 1] = a[scan];
			scan--;
		}
		a[scan + 1] = current;
	}
}

void binaryInsertSort(int a[], int n)
{
	int i, j, left, mid, right, x;
	for (i = 1; i < n; i++)
	{
		x = a[i];
		left = 0;
		right = i - 1;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (x < a[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		for (j = i - 1; j >= left; j--)
			a[j + 1] = a[j];
		a[left] = x;
	}
}

void bubbleSort(int a[], int n)
{

	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	return;
}

void shakeSort(int a[], int n)
{
	bool swapped = true;
	int l = 0, r = n - 1;
	while (swapped)
	{
		swapped = false;
		for (int i = l; i < r; ++i)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
		swapped = false;
		--r;
		for (int i = r - 1; i >= l; --i)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		++l;
	}
	return;
}

void shellSort(int a[], int n)
{
	int gap = n / 2,i , j, temp;
	for (gap; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i += 1)
		{
			temp = a[i];
			for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
				a[j] = a[j - gap];
			a[j] = temp;
		}
	}
}

void heapSort(int a[], int n)
{
	
	while (n > 0)
	{
		heapify(a, n);
		n -= 1;
	}

}

void heapify(int a[],int n)
{
	int indexScan = n-1;
	int lastRoot;
	while (indexScan > 0)
	{
		lastRoot = (indexScan - 1) / 2;
		if (a[lastRoot] < a[indexScan])
			HoanVi(a[lastRoot], a[indexScan]);
		indexScan -= 1;
	}
	HoanVi(a[0], a[n - 1]);
	
}

void merge(int a[], int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int *L = new int[n1], *R = new int[n2];
	for (i = 0; i < n1; i++)
		L[i] = a[left + i];
	for (j = 0; j < n2; j++)
		R[j] = a[mid + 1 + j];
	i = 0; 
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
	delete[] L, R;
	L = NULL;
	R = NULL;
}

void mergeSort(int a[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

void quickSort(int a[], int l, int r)
{
	int i = l, j = r, x = a[(l + r) / 2];
	do
	{
		while (a[i] < x)i++;
		while (a[j] > x)j--;
		if (i <= j)
		{
			HoanVi(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (l < j)
		quickSort(a, l, j);
	if (i < r)
		quickSort(a, i, r);
	
}

void countingSort(int a[],int n)
{
	int i, min = a[0], max = a[0];
	for (i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int *temp = new int[max - min + 1];
	for (i = 0; i < max - min + 1; i++)
		temp[i] = 0;
	for (i = 0; i < n; i++)
		temp[a[i] - min]++;
	for (i = 1; i < max - min + 1; i++)
		temp[i] += temp[i - 1];
	int *ret = new int[n];
	for (i = n - 1; i >= 0; i--)
	{
		ret[temp[a[i] - min] - 1] = a[i];
		temp[a[i]- min] --;
	}
	for (i = 0; i < n; i++)
		a[i] = ret[i];
	delete[] ret, temp;
	ret = NULL;
	temp = NULL;
	
}

int getMax(int a[], int n)
{
	int max = a[0];
	int i;
	for (i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

void countSort(int a[], int n, int exp)
{
	int *output = (int *)malloc(n*sizeof(int));// output array 
	int i, count[10] = { 0 };
	// Store count of occurrences in count[] 
	for (i = 1; i < n; i++)
		count[(a[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual 
   //  position of this digit in output[] 
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array 
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < n; i++)
		a[i] = output[i];
	free(output);
}

void radixSort(int a[], int n)
{

	int m = getMax(a, n);
	int d = 0;
	while (m > 0)
	{
		d++;
		m /= 10;
	}
	int k;
	for (k = 1; k <= d; k++)
		sort(a, n, k);

}

int digit(int a, int k)
{
	int j = 1;
	int ret = 1;
	while (j <= k)
	{
		ret = a % 10;
		a /= 10;
		j += 1;
	}
	return ret;
}

void sort(int a[], int n, int k)
{
	int *b = new int[n];
	int f[10] = { 0 };
	int i, j;
	for (i = 0; i < n; i++)
		f[digit(a[i], k)]++;
	for (i = 1; i < 10; i++)
		f[i] += f[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		j = digit(a[i], k);
		b[f[j] - 1 ]= a[i];
		f[j]--;
	}
	for (i = 0; i < n; i++)
		a[i] = b[i];
	delete[] b;
	b = NULL;

}

void flashSort(int a[], int n)
{
	int grade = 0.45 *n;
	int *s = new int[grade];
	int i, maxIndex = 0, min = a[0];
	for (i = 1; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > a[maxIndex])
			maxIndex = i;
	}

	if (min == a[maxIndex])
	{
		delete[] s;
		s = NULL;
		return;
	}
	int c1 = (grade - 1) / (a[maxIndex] - min);

	for (i = 0; i < grade; i++)
		s[i] = 0;

	int temp;
	for (i = 0; i < n;++i)
	{
		temp = (c1 *(a[i] - min));
		++s[temp];
	}

	for (i = 1; i < grade; ++i)
		s[i] += s[i - 1];

	int hold = a[maxIndex];
	a[maxIndex] = a[0];
	a[0] = hold;
	
	int move = 0, t, flash;
	int j = 0; 
	int k = grade - 1;

	while (move < (n - 1))
	{
		while (j > (s[k] - 1))
		{
			++j;
			k = (c1 * (a[j] - min));
		}
		if (k < 0) break;
		flash = a[j];
		while (j != s[k])
		{
			k = (c1 * (flash - min));
			hold = a[t = --s[k]];
			a[t] = flash;
			flash = hold;
			++move;
		}
	}

	for (j = 1; j < n; j++)
	{
		hold = a[j];
		i = j - 1;
		while (i >= 0 && a[i] > hold)
			a[i + 1] = a[i--];
		a[i + 1] = hold;
	}
	{
		delete[] s;
		s = NULL;
		return;
	}
}