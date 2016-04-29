//----------------------------------------------------------------------
//file: sortMain.cpp
/**
Name: Shanshan Jiang
Course: CSC551 Algorithm
Date: 02/04/2016
Description:
This is the sortMain1.cpp which is uesd to test insertionSort.cpp.
The const N can be changed from 10 to 1000000.
**/
#include <iostream>

#include <ctime> // Needed for the true randomization
#include <cstdlib>
#include <conio.h> //to catch the output screen

//extern void selectionSort(int A[], int n);
extern void insertionSort(int A[], int n);

using namespace std;

int main(int argc, char* argv[]) {

	//N = 10, 100, 1000, 10000, 100000, 200000, 300000, 400000, 500000, 1000000
	const int N = 10;
	//const int N = 100;
	//const int N = 1000;
	//const int N = 10000;
	//const int N = 100000;
	//const int N = 200000;
	//const int N = 300000;
	//const int N = 400000;
	//const int N = 500000;
	//const int N = 1000000;

	int A[N];
	int randomNo;
	srand(time(0)); // This will ensure a really randomized number by help of time.

	for (int i = 0; i< N; i++) {
		randomNo = rand(); // Randomizing the number.
		A[i] = randomNo;
		// cout << " " << A[i];
	}//for

	insertionSort(A, N);

	cin.get();//to keep the consol window

}//main
