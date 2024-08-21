/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief main file for the statistics application 
 *
 * This file contains the definitions of all fuctions used in this application
 * and the entry point of the application
 *
 * @author Chibuike Mowah
 * @date 20 Aug 2024
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  print_array(test, SIZE);
  print_statistics(test, SIZE);
  sort_array(test, SIZE);
  print_array(test, SIZE);
}

void print_statistics(unsigned char *arr, unsigned int size)
{
	printf("Minimum value: %d\n", find_minimum(arr, size));
	printf("Maximum value: %d\n", find_maximum(arr, size));
	printf("Mean value: %d\n", find_mean(arr, size));
	printf("Median value: %d\n", find_median(arr, size));
}

void print_array(unsigned char *arr, unsigned int size)
{
	int i;
	char *delim = "";

	printf("[ ");
	for (i = 0; i < size; i++)
	{
		printf("%s%d", delim, arr[i]);
		if (i == 0)
			delim = ", ";
	}
	puts("]");
}

unsigned char find_median(unsigned char *arr, unsigned int size)
{
	unsigned char median = 0;
	int indices = size - 1;

	sort_array(arr, size);
	if (size % 2)
		median = arr[indices/2] + 1;
	else
		median = (arr[indices/2] + arr[(indices/2) + 1]) / 2;
	return (median);
}

unsigned char find_mean(unsigned char *arr, unsigned int size)
{
	int i, sum;

	i = sum = 0;
	for (; i < size; i++)
		sum += arr[i];
	return (sum / size);

}

unsigned char find_maximum(unsigned char *arr, unsigned int size)
{
	sort_array(arr, size);
	return (arr[0]);
}

unsigned char find_minimum(unsigned char *arr, unsigned int size)
{
	sort_array(arr, size);
	return (arr[size - 1]);
}

void sort_array(unsigned char *arr, unsigned int size)
{
	int i, j, k, left_size = size/2, right_size = size - (size/2);
	unsigned char left_arr[left_size], right_arr[right_size];

	if (size > 1)
	{
		sort_array(arr, left_size);
		sort_array(arr+left_size, right_size);

		for (i = 0; i < left_size; i++)
			left_arr[i] = arr[i];
		for (j = 0; j < right_size; j++)
			right_arr[j] = arr[left_size+j];

		i = j = k = 0;
		while (i < left_size && j < right_size) {
			if (left_arr[i] >= right_arr[j]) {
				arr[k] = left_arr[i];
				i++;
			}
			else {
				arr[k] = right_arr[j];
				j++;
			}
			k++;
		}
		while (i < left_size) {
			arr[k] = left_arr[i];
			i++;
			k++;
		}
		while (j < right_size) {
			arr[k] = right_arr[j];
			j++;
			k++;
		}
	}
}
