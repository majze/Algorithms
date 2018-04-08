#pragma once
#include <iostream>
#include <random>
using namespace std;

inline void SelectionSort(int NumArray[], int ArraySize)
{
	//Sorts a given array by selection sort
	//Input: An array A[0..n-1] of orderable elements
	//Output: Array A[0,,n-1] sorted in nondecreasing order
	for (int i = 0; i <= ArraySize - 2; i++)
	{
		int min = i;
		for (int j = i + 1; j <= ArraySize - 1; j++)
		{
			if (NumArray[j] < NumArray[min])
				min = j;
		}
		int temp = NumArray[i];
		NumArray[i] = NumArray[min];
		NumArray[min] = temp;
	}
	//Θ(n^2) time complexity
}

inline void BubbleSort(int NumArray[], int size)
{
	//Sorts a given array by bubble sort
	//Input: An array A[0..n-1] of orderable elements
	//Output: Array A[0..n-1] sorted in nondecreasing order
	for (int i = 0; i <= size - 2; i++)
	{
		for (int j = 0; j <= size - 2; j++)
		{
			if (NumArray[j + 1] < NumArray[j])
			{
				int temp = NumArray[j];
				NumArray[j] = NumArray[j + 1];
				NumArray[j + 1] = temp;
			}
		}
	}
	//Θ(n^2) time complexity
}

inline int SequentialSearch(int Array[], int size, int K)
{
	//Implements sequential search with a search key as a sentinel
	//Input: An array A of n elements and a search key K
	//Output: The index of the first element in A[0..n-1] whose value is
	//	equal to K or -1 if no such element is found
	Array[size] = K; int i = 0;
	while (Array[i] != K)
		i++;
	if (i < size)
	{
		return i;
	}
	else {
		return -1;
	}
}

inline void ShuffleArray(int DataArray[], int ArraySize)
{
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