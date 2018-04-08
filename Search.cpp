#pragma once
#include <iostream>
using namespace std;

inline int BinarySearch(int A[], int n, int K)
{
	//Implements nonrecursive binary search
	//Input: An array A[0..n-1] sorted in ascending order and a search key K
	//Output: An index of the array's element equal to K or -1 if none exists
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (K == A[m])
		{
			return m;
		}
		else if (K < A[m]) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return -1;
	//Θ(log_2_(n)) average time complexity
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