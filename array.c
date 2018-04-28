#include <stdio.h>
#include <stdlib.h>
#include "catalog.h"

// --------- Questions on Binary Search ----------
// 1. Find the minimum element in a sorted rotated array.
/**min_sorted_rotated_array: finds the min element in the sorted rotated array
 *
 * @A[]: Sorted Rotated Array
 * n: 		Size of the array
 */
int min_sorted_rotated_array(int A[], int start, int end){
	printf("\nMin. element in Sorted rotated array\n");

	int mid, min;
	mid = start + (end - start)/2;

	if (A[mid]>A[mid+1]){
		min= mid+1;
	}

	if (A[mid-1]>A[mid]){
		min = mid;
	}

	if (A[end]>A[mid])
		min_sorted_rotated_array(A,start, mid-1);
	else
		min_sorted_rotated_array(A, mid+1, end);

	return min;
}

/* 2. First Occurrence
 * Given a Sorted array of n elements, possibly with Duplicates.
 * Find the Index of the first occurrence of a number.
 */

int first_occurrence(int A[], int n, int data){
	int start, end, mid;
	int index;

	start = 0;
	end = n-1;
	index = -1;

	while (start<=end){
		mid = start + (end-start)/2;

		if ((A[mid]==data && A[mid-1]<data) || (A[mid]==data && mid==start)){
			index = mid;
			return index;
		}
		else if (A[mid] < data){
			start = mid+1;
		}
		else
			end = mid-1;
	}
	return index;
}

/* 3. Last Occurrence
 * Given a Sorted array of n elements, possibly with Duplicates.
 * Find the Index of the last occurrence of a number.
 */
int last_occurrence(int A[], int n, int data){
	int start, end, mid;
	int index;

	start = 0;
	end = n-1;
	index = -1;

	while (start<=end){
		mid = start + (end-start)/2;
		//printf("mid=%d A[mid]=%d\n", mid, A[mid]);

		if ((A[mid]==data && A[mid+1]>data) || (A[mid]==data && mid==end)){
			index = mid;
			return index;
		}
		else if (A[mid] <= data){	// <--- Pay Attention here
			start = mid+1;
		}
		else
			end = mid-1;
	}
	return index;
}

/* 4. Given a sorted array possibly with Duplicates.
 * 	  Find the number of occurrences of a number.
 */
int number_of_occurrences_of_data(int A[], int n, int data) {
	int last, first, number;

	last = last_occurrence(A, n, data);
	//printf("last : %d", last);
	first = first_occurrence(A, n, data);
	//printf("first : %d", first);

	number = 1+last-first;
	return number;
}

/* 5. Find if an array is a subset of another array or not.
 */
int is_subset(int A[], int B[], int n, int m){
	// Sort the Array A first
	// Binary Search all the elements in Array B in array A

	int ret = -1;

	for (int i = 0; i<m; i++) {
		ret = binary_search_iterative(A, 0, n, B[i]);
		if (ret == -1)
			return 0;
	}
	return 1;
}

/* 6. Listy: Sorted Search, No Size:
 * You are given an array-like data structure Listy which lacks a size method.
 * It does, however, have an elementAt(i) method that returns the
 * element at index i in 0(1) time.
 * If i is beyond the bounds of the data structure, it returns -1.
 * (For this reason, the data structure only supports positive integers.)
 * Given a Listy which contains sorted, positive integers, find the index at
 * which an element x occurs.
 * If x occurs multiple times, you may return any index.
 */
/**
 * search_in_listy - Searches a "value" in the listy data structure (a array)
 * We dont know the size of the listy data structure.
 */
void search_in_listy(int *listy, int value, int size_of_listy){
	int index = 1;

	while ((elementAt(listy, index, size_of_listy) != -1) &&
			(elementAt(listy, index, size_of_listy) < value)){
		index = index*2;
	}

	int result = binary_search_iterative(listy, index/2, index, value);

	printf("Listy Result = %d\n", result);
	return;
}

// Tweak in Binary Search in Listy
int binary_search_in_listy(){
	return 0;
}










// ---------- Utility Functions -------------------------
//Print Array
void print_array (int arr[], int n) {
	int i;

	printf("\nArray : ");
	for(i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// Returns the element at ith index in the array.
int elementAt(int A[], int i, int size){
	if (i < size){
		return A[i];
	}

	return -1;
}

// Reverse an Array
/**
 * reverse_array: reverse an array
 * @A:	Input array
 * @n:	size of the array
 *
 * A 	= 1 3 4 9 2
 * rA 	= 2 9 4 3 1
 */

void reverse_array(int A[], int n){
	printf("\nReversing array now\n");
	int start, end;
	int temp;

	start = 0;
	end = n-1;

	while (start <= end){
		swap(&A[start], &A[end]);
		start++;
		end--;
	}
}

//Q. How to access array elements without using index and pointer increment variable?


