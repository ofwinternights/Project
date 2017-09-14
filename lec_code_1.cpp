//C++ program to find maximum occured element in given N ranges.
#include <iostream>
#include <algorithm>
#include <cstring>
#include <conio.h>
using namespace std;

// Return the maximum occurred element in all ranges.
int maximumOccuredSmallestElement(int L[], int R[], int n, int largest)
{
	// Initalising all element of array to 0.
	int prefixArray[largest];
	memset(prefixArray, 0, n);


}
// Driven Program
int main()
{
	int L[] = { 1, 4, 9, 13, 21 };
	int R[] = { 15, 8, 12, 20, 30 };
	int largest = 0;
	int n = sizeof(L) / sizeof(L[0]);
	for (int i = 0; i<n; i++) {
		largest = max(largest, max(L[i], R[i]));
	}
	cout << maximumOccuredSmallestElement(L, R, n, largest + 1) << endl;
	getch();
	return 0;

}