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

void quick_sort(int from, int to)
{
	int i, j; //배열의 인덱스 변수 i, j
	int t; //i와 j의 배열 값을 바꿀 때 임시 저장할 변수
	int temp; //기준이 되는 pivot값과 배열의 값을 바꿀 때 임시 저장할 변수

	if (to > from)
	{
		temp = L[to]; i = from-1; j = to;
		do {
			do { i = i + 1; } while (L[i] < temp);
			do { j = j - 1; } while (L[j] > temp);
			if (i < j) {
				//배열의 i와 j번째 값 swap
				t = L[i]; L[i] = L[j]; L[j] = t;
			}
		} while (j > i);

		//swap L[to](->pivot) and L[i]
		t = L[i]; L[i] = L[to]; L[to] = t;
		quick_sort(from, i - 1);
		quick_sort(i + 1, to);
	}
}

int main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	quick_sort(0, SIZE - 1);

	cout << "\n\nSorted Data : ";
	print_data();

}
