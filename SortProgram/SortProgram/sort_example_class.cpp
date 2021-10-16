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

void insertion_sort()
{
	int i, j;
	int temp;

	for (i = 1; i < SIZE; i++)
	{
		temp = L[i];
		for (j = i; j > 0; j--)
		{
			if (L[j - 1] > temp) L[j] = L[j - 1];
			else break;
		}
		L[j] = temp;
	}
}

int main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	insertion_sort();

	cout << "\n\nSorted Data : ";
	print_data();

}
