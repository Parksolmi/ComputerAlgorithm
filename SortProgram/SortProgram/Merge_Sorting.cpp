//디지털미디어학과 2020111263 박솔미
#include <iostream>
using namespace std;

const int SIZE = 15;
int L[SIZE] = { 10, 4, 7, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };


void print_data()
{
	for (int i = 0; i < SIZE; i++)
		cout << " " << L[i] << " ";
	cout << endl;
}

void merge(int from, int mid, int to)
{
	int i, j, k;

	i = from;
	j = mid + 1;
	k = from;

	int temp_arr[SIZE] = { 0 };

	while (i <= mid && j <= to)
	{
		if (L[i] <= L[j]) temp_arr[k++] = L[i++];
		else temp_arr[k++] = L[j++];
	}
	
	if (i > mid)
	{
		for (int m = j; m <= to; m++)
		{
			temp_arr[k++] = L[m];
		}
	}
	else
	{
		for (int m = i; m <= mid; m++)
		{
			temp_arr[k++] = L[m];
		}
	}

	for (int m = from; m <= to; m++)
	{
		L[m] = temp_arr[m];
	}
}

void merge_sort(int from, int to)
{
	int mid;

	if (from < to)
	{
		mid = (from + to) / 2;
		merge_sort(from, mid);
		merge_sort(mid + 1, to);
		merge(from, mid, to);
	}
}

int main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	merge_sort(0, SIZE - 1);

	cout << "\n\nSorted Data : ";
	print_data();

}
