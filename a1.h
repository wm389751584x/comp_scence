/*
 * a1.h
 *
 *  Created on: Feb 13, 2015
 *      Author: Jason
 */

#ifndef A1_H_
#define A1_H_

typedef int bool;

typedef struct list {
	int age;
	int occurs;
	struct list * next;
} list_t;

void init(list_t * list);

void fd_mode(list_t * list);

bool insert(list_t * list, int val);

bool raw_insert(list_t * list, int val);

int * set_width(list_t * list);


#endif /* A1_H_ */
