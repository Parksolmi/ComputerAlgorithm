//�����й̵���а� 2020111263 �ڼֹ�
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
	int i, j; //�迭�� �ε��� ���� i, j
	int t; //i�� j�� �迭 ���� �ٲ� �� �ӽ� ������ ����
	int temp; //������ �Ǵ� pivot���� �迭�� ���� �ٲ� �� �ӽ� ������ ����

	if (to > from)
	{
		temp = L[to]; i = from-1; j = to;
		do {
			do { i = i + 1; } while (L[i] < temp);
			do { j = j - 1; } while (L[j] > temp);
			if (i < j) {
				//�迭�� i�� j��° �� swap
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
