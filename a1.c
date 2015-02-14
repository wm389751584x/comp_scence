/*
 * a1.c
 *
 *  Created on: Feb 13, 2015
 *      Author: Jason
 */
//This is my second time of assignment 1. I think I need some extra points
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "a1.h"

int main(void) {
	float mean = 0;
	int i, j;
	int minimum, fquartile = 0, median = 0, tquartile = 0, maximum = 0;
	int temp;
	int count = 27;
	int depth = 3;
	int bin_count = count / 3;
	float midrange;
	list_t mylist;
	init(&mylist);
	int age[] = { 13, 15, 16, 16, 19, 20, 20, 21, 22, 22, 25, 25, 25, 25, 30,
			33, 33, 35, 35, 35, 35, 36, 40, 45, 46, 52, 70 };
	//find max, min
	minimum = age[0];
	for (i = 0; i < count; i++) {
		if (minimum > age[i])
			minimum = age[i];
		if (maximum < age[i])
			maximum = age[i];
	}
	//print mean
	for (i = 0; i < count; i++) {
		mean += age[i];
	}
	mean /= count;
	printf("Q1\n");

	printf("a.\n");
	printf("mean is: %.4f\n", mean);
	midrange = (maximum + minimum) / 2;
	printf("midrange is: %.4f\n", midrange);

	printf("b.\n");
	//find mode
	for (i = 0; i < count; i++) {
		insert(&mylist, age[i]);
	}
	fd_mode(&mylist);

	printf("c.\n");
	printf("minimum is: %d\n", minimum);
	//find median
	temp = count / 2;
	if (count % 2 == 0) {
		median = age[temp] + age[temp - 1];
		median /= 2;
	} else {
		median = age[temp - 1];
		temp++;
	}
	printf("median is: %d\n", median);
	//find fist quart
	if (temp % 2 == 0) {
		temp /= 2;
		fquartile = age[temp - 1] + age[temp];
		fquartile /= 2;
	}
	printf("fist quartile: %d\n", fquartile);
	temp = (temp) * 3 - 1;
	tquartile = age[temp];
	printf("third quartile: %d\n", tquartile);
	printf("maximum is: %d\n", maximum);
	printf("Q2\n");
	printf("a.\n");
	int bin1[9], bin2[9], bin3[9];
	for (i = 0; i < bin_count; i++) {
		bin1[i] = age[i];
		bin2[i] = age[i + 9];
		bin3[i] = age[i + 18];
	}
	float mean1 = 0, mean2 = 0, mean3 = 0;
	for (i = 0; i < bin_count; i++) {
		mean1 += bin1[i];
		mean2 += bin2[i];
		mean3 += bin3[i];
	}
	mean1 /= bin_count;
	mean2 /= bin_count;
	mean3 /= bin_count;
	printf("bin1: ");
	for (j = 0; j < bin_count; j++) {
		printf("%.4f ", mean1);
	}
	printf("\n");
	printf("bin2: ");
	for (j = 0; j < bin_count; j++) {
		printf("%.4f ", mean2);
	}
	printf("\n");
	printf("bin3: ");
	for (j = 0; j < bin_count; j++) {
		printf("%.4f ", mean3);
	}
	printf("\n");
	printf("b.\n");
	int lbn1 = 13, hbn1 = 22, lbn2 = 22, hbn2 = 35, lbn3 = 35, hbn3 = 70;
	printf("bin1: ");
	for (i = 0; i < bin_count; i++) {
		if (bin1[i] - lbn1 <= hbn1 - bin1[i])
			printf("%d ", lbn1);
		else
			printf("%d ", hbn1);
	}
	printf("\n");
	printf("bin2: ");
	for (i = 0; i < bin_count; i++) {
		if (bin2[i] - lbn2 <= hbn2 - bin2[i])
			printf("%d ", lbn2);
		else
			printf("%d ", hbn2);
	}
	printf("\n");
	printf("bin3: ");
	for (i = 0; i < bin_count; i++) {
		if (bin3[i] - lbn3 <= hbn3 - bin3[i])
			printf("%d ", lbn3);
		else
			printf("%d ", hbn3);
	}
	printf("\n");
	printf("c.\n");

	return 0;

}
