/*
 * main.c
 *
 *  Created on: Oct 20, 2017
 *      Author: hsahu
 */
#include <stdio.h>
#include <stdlib.h>
#include "catalog.h"

int main () {
	int size, ret;
	int start, end;
	int data;

	int A[] = {5, 10,999, -2, 1, 3, 2, 4, -1000 };

	size = sizeof(A)/sizeof(A[0]);
	printf("Size of Array A: %d\n", size);

	data = 3;
	ret = linear_search(A, size, data);
	printf("data %d is at index %d\n", data, ret);

	int B[] = {0,1,2,3,4,5,6,7,8,9};
	size = sizeof(B)/sizeof(B[0]);
	printf("Size of Array B: %d\n", size);

	start = 0;
	end = size-1;

	data = -20;
	//ret = binary_search_recursive(B, start, end, data);
	ret = binary_search_iterative(B, start, end, data);
	printf("data %d is at index %d\n", data, ret);
	print_array(B, size);
	//rotate_array(B, size, 3);
	//print_array(B, size);
	reverse_array(B, size);
	print_array(B, size);

/*	int C[] = {8,9,0,1,2,3,4,5,6,7};
	size = sizeof(C)/sizeof(C[0]);
	print_array(C, size);
	printf("Size of Array C: %d\n", size);

	start = 0;
	end = size-1;
*/
	//ret = min_sorted_rotated_array(C, start, end);
	//printf("min element %d is at index %d\n", C[ret], ret);

	int C[] = {1,2,4,4,4,4,4,5,6,7};
	size = sizeof(C)/sizeof(C[0]);
	print_array(C, size);
	printf("Size of Array C: %d\n", size);

	start = 0;
	end = size-1;
	data = 4;

	ret = first_occurrence(C, size, data);
	printf("first occurrence of the data %d is at index %d\n", data, ret);

	ret = last_occurrence(C, size, data);
	printf("last occurrence of the data %d is at index %d\n", data, ret);

	ret = number_of_occurrences_of_data(C, size, data);
	printf("number of occurrence of the data %d are %d\n", data, ret);

	int D[] = { 1, 2, 4, 5, 9};
	int n = sizeof(D)/sizeof(D[0]);
	int E[] = {5,9, 7};
	int m = sizeof(E)/sizeof(E[0]);

	printf("A is a Subset of B = %d", is_subset(D, E, n, m));

	search_in_listy(D, 3, n);

	return 0;
}
