#include <iostream>
using namespace std;
void copy_arr(double* arr, double* source, int len) {
	for (int i = 0; i < len; ++i) {
		*(arr + i) = *(source + i);
	}
}
void copy_arr1(double arr[], double source[], int len) {
	for (int i = 0; i < len; ++i) {
		arr[i] = source[i];
	}
}
void copy_arr2(double* arr, double* source_start, double* source_end) {
	for (int i = 0; i < *source_end; ++i) {
		*(arr + i) = *(source_start + i);
	}
}
void copy_arr3(double* arr, double* source_start, double* source_end) {
	for (; *source_start < *source_end; source_start++) {
		*arr = *source_start;
		arr++;
	}
}
int main()
{
	double source[5] = { 1.1,2.2,3.3,4.4,5.5 };
	double arr[5];
	double n = 5;
	double* p = &n;
	
	copy_arr3(arr, source,source+5);
	for (int i = 0; i < sizeof(source)/sizeof(double); i++) {
		cout << *(arr+i)<< endl;
	}
}