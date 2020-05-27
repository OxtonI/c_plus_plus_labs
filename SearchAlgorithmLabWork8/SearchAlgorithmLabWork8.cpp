#include <iostream>
#include <ctime>

using namespace std;

int Search(int* startArray, int neededValue)
{
	const int N = 1000;
	for (int i = 0; i < N; i++)
	{
		if (startArray[i] == neededValue)
		{
			cout << "Значение элемента есть в массиве" << endl;
			return startArray[i];
		}
	}
	cout << "Значение элемента не найдено" << endl;
}

int BinarySearch1(int value, int* array, int left, int right)
{
	bool mark = false;
	int mid;
	while ((left <= right) && (mark != true))
	{
		mid = (left + right) / 2;
		if (array[mid] == value)
			mark = true;
		if (array[mid] > value)
			right = mid - 1;
		else
			left = mid + 1;
	}

	if (mark)
	{
		cout << "Значение элемента есть в массиве" << endl;
		return mid;
	}

	else
	{
		cout << "Значение элемента не найдено" << endl;
		return -1;
	}
}

int BinarySearch2(int array[], int value, int left, int right)
{
	int middle = (left + right) / 2;
	if (array[middle] == value)
	{
		cout << "Значение элемента есть в массиве" << endl;
		return middle;
	}

	if (middle == left || middle == right)
	{
		cout << "Значение элемента не найдено" << endl;
		return -1;
	}

	if (array[middle] < value) BinarySearch2(array, value, middle, right - 1);
	else BinarySearch2(array, value, left, middle - 1);
}

void QuickSort1(int* array, int first, int last)
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

void QuickSort2(int* array, int first, int last)
{
	int mid;
	while (first < last) {
		mid = array[(first + last) / 2];
		while (array[first] < mid)
			first++;
		while (mid < array[last])
			last--;
		if (first <= last)
		{
			int temp = array[first];
			array[first] = array[last];
			array[last] = temp;
			first++;
			last--;
		}
		if (first < last)
			first = first;
		else if (first < last)
		{
			last = last;
			first++;
		}
	}
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

	clock_t start, end;
	start = clock();
	Search(Array, 666);
	end = clock();
	cout << "Время поиска неотсортированного массива линейным поиском: " << (((double)end - start) / ((double)CLOCKS_PER_SEC)) << endl;

	start = clock();
	BinarySearch1(666, Array, 0, N - 1);
	end = clock();
	cout << "Время поиска неотсортированного массива бинарным поиском: " << (((double)end - start) / ((double)CLOCKS_PER_SEC)) << endl;

	QuickSort1(Array, 0, N - 1);

	QuickSort2(Array, 0, N - 1);

	start = clock();
	BinarySearch2(Array, 213, 0, N - 1);
	end = clock();
	cout << "Время поиска отсортированного массива бинарным поиском: " << (((double)end - start) / ((double)CLOCKS_PER_SEC)) << endl;

	start = clock();
	Search(Array, 666);
	end = clock();
	cout << "Время поиска отсортированного массива линейным поиском: " << (((double)end - start) / ((double)CLOCKS_PER_SEC)) << endl;
}
