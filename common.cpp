#pragma once
#include <iostream>
#include <random>
#include "Search.cpp"
#include "Sort.cpp"
using namespace std;

inline void ShuffleArray(int DataArray[], int ArraySize)
{
	//Randomly generates a new set of numbers using old data
	//No best method, simply have fun
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, ArraySize - 1);
	int rando = distribution(generator);
	for (int i = 0; i <= ArraySize - 1; i++)
	{
		if (i > 0)
		{
			DataArray[i] = DataArray[rando] + (DataArray[i - 1] % 2) * rando + rando;
		}
		else {
			DataArray[0] = rando + DataArray[rando];
		}
	}
}

inline void PrintArray(int DataArray[], int ArraySize, int verboose)
{
	//Prints the Array
	//Verboose modification can be helpful for larger data structures
	cout << "\nArray:\n";
	for (int i = 0; i <= ArraySize - 1; i++)
	{
		if (verboose == 1) {
			cout << "\n[" << i << ": " << DataArray[i] << "]";
		}
		else {
			cout << "[" << DataArray[i] << "]\t";
		}
	}
	cout << endl << endl;
}

inline void SortMenu(int A[], int size)
{
	int menu = 0;
	while (menu > -1)
	{
		cout << "\n[1: Print]  [2: Randomize]  [3: SelectionSort]  [4: BubbleSort]  [5: InsertionSort] [-1: Back]";
		cout << "\nChoose command: ";
		cin >> menu;

		switch (menu) {
		case 1:
			PrintArray(A, size, 1);
			break;
		case 2:
			ShuffleArray(A, size);
			break;
		case 3:
			SelectionSort(A, size);
			break;
		case 4:
			BubbleSort(A, size);
			break;
		case 5:
			InsertionSort(A, size);
			break;
		default:
			break;
		}

		if (menu != 1)
			PrintArray(A, size, 0);
	}
}

inline void SearchMenu(int A[], int size)
{
	int menu = 0;
	while (menu > -1)
	{
		cout << "\n[1: Print]  [2: Randomize]  [3: SequentialSearch]  [4: BinarySearch] [-1: Back]";
		cout << "\nChoose command: ";
		cin >> menu;

		switch (menu) {
		case 1:
			PrintArray(A, size, 1);
			break;
		case 2:
			ShuffleArray(A, size);
			break;
		case 3:
		{
			int K = 0;
			cout << "\nEnter element to sequentially search for: ";
			cin >> K;
			int result = SequentialSearch(A, size, K);
			if (result == -1)
			{
				cout << "\nNo result found.";
			}
			else {
				cout << "\nElement " << K << " found in index " << result;
			}
			break;
		}
		case 4:
		{
			int K = 0;
			cout << "\nEnter element to binary search for: ";
			cin >> K;
			int result = BinarySearch(A, size, K);
			if (result == -1)
			{
				cout << "\nNo result found.";
			}
			else {
				cout << "\nElement " << K << " found in index " << result;
			}
			break;
		}
		default:
			break;
		}

		if (menu != 1)
			PrintArray(A, size, 0);
	}
}