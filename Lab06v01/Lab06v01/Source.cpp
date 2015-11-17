#include "Array.h"
#include <iostream>
#include <time.h>
using namespace std;

void main() {
	srand(time(0));
	Array arr1(rand() % 4 + 3);
	arr1.SetRand(-99, 99);
	cout << "Arr1 = " << arr1 << endl;
	Array arr2(rand() % 4 + 3);
	arr2.SetRand(-99, 99);
	cout << "Arr2 = " << arr2 << endl;
	Array arr3 = arr1 * arr2;
	cout << "Arr3 = Arr1 * Arr2 = " << arr3 << endl;
	cout << "Arr3[2] = " << arr3[2] << endl;
	cout << "(int)Arr3 = " << (int)arr3 << endl;
	Array arr4 = arr1;
	cout << "Arr4 = Arr1 = " << arr4 << endl;
	cout << "(Arr3 == Arr1) = " << (arr3 == arr1) << endl;
	cout << "(Arr4 == Arr1) = " << (arr4 == arr1) << endl;
}