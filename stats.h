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
 * @file stats.h
 * @brief header file of the statistics application
 *
 * This file contains all the declarations of the functions used in the
 * statistics application and their respective documentation.
 *
 * @author Chibuike Mowah
 * @date 20th August 2024.
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief prints the statistics of an array
 *
 * This takes as input an array of unsigned characters and the array's size.
 * This function prints the statistics of an array including minimum,
 * maximum, mean, and median.
 *
 * @arr: array to be analyzed
 * @size: size of array to be analyzed
 */
void print_statistics(unsigned char *arr, unsigned int size);

/**
 * @brief prints an array of unsigned characters to the screen
 *
 * This takes as input an array of unsigned characters and the array's size.
 * This function prints the characters of the array unto the screen as
 * comma-separated values
 *
 * @arr: array to be printed
 * @size: size of the array to be printed
 */
void print_array(unsigned char *arr, unsigned int size);

/**
 * @brief returns the median value
 *
 * This takes as input an array of unsigned characters and the array's size.
 * This function locates and returns the median value of the array.
 *
 * @arr: array to be analyzed
 * @size: size of the array to be printed
 * @return: the median value
 */
unsigned char find_median(unsigned char *arr, unsigned int size);

/**
 * @brief returns the mean value
 *
 * This takes as input an array of unsigned characters and the array's size.
 * This function calculates and returns the average value of the array.
 *
 * @arr: array to be analyzed
 * @size: size of the array to be analyzed
 * @return: the mean value
 */
unsigned char find_mean(unsigned char *arr, unsigned int size);

/**
 * @brief returns the maximum value
 *
 * This takes as input an array of unsigned characters and the array's size.
 * This function sorts a copy of the array and returns the maximum value.
 *
 * @arr: array to be analyzed
 * @size: size of the array to be analyzed
 * @return: the maximum value
 */
unsigned char find_maximum(unsigned char *arr, unsigned int size);

/**
 * @brief returns the minimum value
 *
 * This takes as input an array of unsigned characters and the array's size.
 * This function sorts a copy of the array and returns the minimum value.
 *
 * @arr: array to be analyzed
 * @size: size of the array to be analyzed
 * @return: the minimum value
 */
unsigned char find_minimum(unsigned char *arr, unsigned int size);

/**
 * @brief returns the maximum value
 *
 * This takes as input an array of unsigned characters and the array's size.
 * This function sorts a copy of the array and returns the maximum value at
 * the zeroth index and the minumum value at the (size-1)th index of the array.
 *
 * @arr: array to be sorted
 * @size: size of the array to be sorted
 */
void sort_array(unsigned char *arr, unsigned int size);

#endif /* __STATS_H__ */
