#include <iostream>
#include "common.cpp"
using namespace std;

int main() {
	//example Array
	int A[10] = { 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 };
	int size = sizeof(A) / sizeof(*A);
	
	int menu = 0;
	while (menu > -1)
	{
		cout << "\n[1: Sorting]  [2: Searching]  [3: TBA]  [4: TBA]  [5: TBA]";
		cout << "\nChoose command: ";
		cin >> menu;

		switch (menu) {
		case 1:
			SortMenu(A, size);
			break;
		case 2:
			SearchMenu(A, size);
			break;
		}
	}
		

	cin.get();
	return 0;
}