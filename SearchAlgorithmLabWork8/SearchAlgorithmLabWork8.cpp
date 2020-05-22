#include <iostream>
#include <ctime>

using namespace std;

int Search(int* startArray, int neededValue)
{
	const int N = 1000;
	for (int i = 0; i < N; i++) 
	{
		if (startArray[i] == neededValue) {
			cout << "Значение элемента есть в массиве";
			return startArray[i];
		}
	}
	cout << "Значение элемента не найдено";
}

void QuickSort(int* array, int first, int last)
{
	int mid, count;
	mid = array[(first + last) / 2];
	do
	{
		while (array[first] < mid) first++;
		while (array[last] > mid) last--;
		if (first <= last)
		{
			count = array[first];
			array[first] = array[last];
			array[last] = count;
			first++;
			last--;
		}
	} 
	while (first < last);
	if (first < last) QuickSort(array, first, last);
	if (first < last) QuickSort(array, first, last);
}


int main()
{
	setlocale(LC_ALL, "Russian");
	const int N = 1000;
	int Array[N];
	const int minValue = -1000;
	const int maxValue = 1000;
	srand(time(NULL));
	for (int i = 0; i < N; i++) 
	{
		Array[i] = rand() % (maxValue - minValue + 1) + minValue;
		cout << Array[i] << endl;
	}
	Search(Array, 666);
}

