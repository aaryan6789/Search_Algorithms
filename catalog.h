/*
 * catalog.h
 *
 *  Created on: Oct 21, 2017
 *      Author: hsahu
 */

#ifndef CATALOG_H_
#define CATALOG_H_

// array
void print_array(int A[], int);
int linear_search(int A[], int, int);
void reverse_array(int A[], int);


// binary_search
int binary_search_recursive(int A[], int , int , int);
int binary_search_iterative(int A[], int , int , int);
int min_sorted_rotated_array(int A[], int , int);
int first_occurrence(int A[], int n, int data);
int last_occurrence(int A[], int n, int data);
int number_of_occurrences_of_data(int A[], int n, int data);
int is_subset(int A[], int B[], int n, int m);

#endif /* CATALOG_H_ */
