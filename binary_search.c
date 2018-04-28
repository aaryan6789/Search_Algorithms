#include <stdio.h>
#include <stdlib.h>
#include "catalog.h"

/*
 * binary_search.c
 * Searching is the process of finding an element with specified properties from
 * a collection of items e.g. database,
 * 							  array,
 * 							  text in files,
 * 							  nodes in a tree
 *
 * 	@Input: a SORTED ARRAY.
 * 	@output: the index of the element of the data or -1 if not found
 */

int binary_search_recursive(int A[], int start, int end, int data) {
	printf("\nRecursive Binary Search\n");
	int mid;

	if (start > end) {
		return -1;
	}

	mid = start + (end- start)/2;

	if (A[mid] == data) {
		return mid;
	} else if (A[mid] < data){
		start = mid+1;
		return binary_search_recursive(A, start, end, data);
	} else {
		end = mid-1;
		return binary_search_recursive(A, start, end, data);
	}
}

int binary_search_iterative(int A[], int start, int end, int data) {
	printf("\nIterative Binary Search\n");
	int mid;

	while (start <= end){			// <---- Pay attention here, <= not just < for boundary conditions
		mid = start + (end-start)/2;

		if (A[mid] == data){
			return mid;
		}
		else if (A[mid] < data) {
			start = mid + 1;
		}
		else if (A[mid] > data) {
		end = mid-1;
		}
	}
	return -1;
}

// Linear Search in Array
/**
 * linear_search : Search a given element in an array
 * @A[]: 	Input array (Sorted or unsorted)
 * @n: 		size of the array
 * @data: 	Element to search for
 * @return: Index of the data, -1 if no element in the array
 */
int linear_search(int A[], int n, int data){
	printf("\nLinear Search in Array\n");
	int i;

	for (i = 0; i<n; i++) {
		if (A[i] == data){
			return i;
		}
	}
	return -1;
}

