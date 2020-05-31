#include <iostream>
#include <ctime>
#include <random>

using namespace std;

int Search(int* startArray, int neededValue)
{
	const int N = 100;
	for (int i = 0; i < N; i++)
	{
		if (startArray[i] == neededValue)
		{
			cout << "Значение элемента " << neededValue << " есть в массиве" << endl;
			return startArray[i];
		}
	}
	cout << "Значение элемента " << neededValue << " НЕ найдено" << endl;
}

int BinarySearch1(const int* array, int value, int left, int right)
{
	int search = -1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (value == array[middle])
		{
			search = array[middle];
			break;
		}
		if (value < array[middle])
			right = middle - 1;
		else
			left = middle + 1;
	}
	if (search == -1)
	{
		cout << "Значение элемента " << value << " НЕ найдено" << endl;
		return search;
	}
	else
	{
		cout << "Значение элемента " << search << " есть в массиве" << endl;
		return search - 1;
	}
}

int BinarySearch2(int* array, int value, int left, int right)
{
	int middle = (left + right) / 2;
	if (array[middle] == value)
	{
		cout << "Значение элемента " << value << " есть в массиве" << endl;
		return middle;
	}

	if (middle == left || middle == right)
	{
		cout << "Значение элемента " << value << " НЕ найдено" << endl;
		return -1;
	}

	if (array[middle] < value) BinarySearch2(array, value, middle, right - 1);
	else BinarySearch2(array, value, left, middle - 1);
}

void QuickSort1(int* array, int first, int last)
{
	int x = first;
	int y = last;
	int size = last - first + 1;
	int mid = array[first + size / 2];
	while (x <= y)
	{
		while (array[x] < mid) x++;
		while (array[y] > mid) y--;
		if (x <= y)
		{
			int temp = array[x];
			array[x] = array[y];
			array[y] = temp;
			x++;
			y--;
		}
	}
	if (y > first)
		QuickSort1(array, first, y);
	if (x < last)
		QuickSort1(array, x, last);
}

void QuickSort2(int* array, int first, int last)
{
	int pivot;
	int left = first;
	int right = last;
	while (left < right) {
		pivot = array[(left + right) / 2];
		while (array[left] < pivot)
			left++;
		while (pivot < array[right])
			right--;
		if (left <= right)
		{
			int temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			left++;
			right--;
		}
		if (first < right)
			left = first;
		else if (left < last)
		{
			right = last;
			first++;
		}
	}
}

void PrintElements(int* array, int num)
{
	cout << "Первые " << num << " элементов: ";
	for (int i = 0; i < num; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void RandomArrayFill(int* array, int size, int min, int max)
{
	std::default_random_engine generator(time(0));
	std::uniform_int_distribution<int> random(min, max);
	for (int i = 0; i < size; ++i)
	{
		array[i] = random(generator);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int N = 100;
	int Array[N];
	const int minValue = -10;
	const int maxValue = 10;
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		Array[i] = rand() % (maxValue - minValue + 1) + minValue;
	}

	int testQuickSort1[100];
	RandomArrayFill(testQuickSort1, 100, -10, 10);
	PrintElements(testQuickSort1, 50);
	QuickSort1(testQuickSort1, 0, 99);
	PrintElements(testQuickSort1, 50);

	int testQuickSort2[100];
	RandomArrayFill(testQuickSort2, 100, -10, 10);
	PrintElements(testQuickSort2, 50);
	QuickSort2(testQuickSort2, 0, 99);
	PrintElements(testQuickSort2, 50);

	int testBinarySearch[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	clock_t start, end;
	start = clock();
	Search(Array, 6);
	end = clock();
	cout << "Время поиска неотсортированного массива линейным поиском: " << (((double)end - start) / ((double)CLOCKS_PER_SEC)) << endl << endl;

	start = clock();
	cout << "Индекс этого элемента: " << BinarySearch1(testBinarySearch, 8, 0, sizeof(testBinarySearch) / sizeof(testBinarySearch[0])) << endl;
	end = clock();
	cout << "Время поиска неотсортированного массива бинарным поиском: " << (((double)end - start) / ((double)CLOCKS_PER_SEC)) << endl << endl;

	start = clock();
	cout << "Индекс этого элемента: " << BinarySearch2(testBinarySearch, 8, 0, sizeof(testBinarySearch) / sizeof(testBinarySearch[0])) << endl;
	end = clock();
	cout << "Время поиска отсортированного массива бинарным поиском: " << (((double)end - start) / ((double)CLOCKS_PER_SEC)) << endl << endl;

	start = clock();
	Search(Array, 6);
	end = clock();
	cout << "Время поиска отсортированного массива линейным поиском: " << (((double)end - start) / ((double)CLOCKS_PER_SEC)) << endl << endl;
}