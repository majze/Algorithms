#include <iostream>
#include "Sort.cpp"
using namespace std;

int main() {
	//example Array
	int A[10] = { 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 };
	int size = sizeof(A) / sizeof(*A);
	
	int menu = 0;
	while (menu > -1)
	{
		cout << "\n[1: Print Array]  [2: Shuffle Array]  [3: SelectionSort]  [4: BubbleSort]  [5: SequentialSearch]";
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
			int K = -1;
			cout << "\nEnter value to search for: ";
			cin >> K;
			cout << "The first occurence of " << K << " is in the index of numerical value " << SequentialSearch(A, size, K) << endl;
			break;
		}

		if (menu != 1)
			PrintArray(A, size, 0);
	}

	cin.get();
	return 0;
}