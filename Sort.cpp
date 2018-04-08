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

inline void InsertionSort(int Array[], int size)
{
	//Sorts a given array by insertion sort
	//Input:An array A[0..n-1] of n orderable elements
	//Outout: Array A[0..n-1] sorted in nondecreasing order
	for (int i = 0; i <= size - 1; i++)
	{
		int v = Array[i];
		int j = i - 1;
		while (j >= 0 && Array[j] > v)
		{
			Array[j + 1] = Array[j];
			j -= 1;
		}
		Array[j + 1] = v;
	}
	//Θ(n^2) time complexity, better than bubble sort on averager
}