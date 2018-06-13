#ifndef VECTOR_H__
#define VECTOR_H__


typedef struct vector {
	int number;
	struct vector * next;
} Vector;

Vector * Vector_new(int number);
void Vector_addLast(Vector ** self, Vector * node);
void Vector_freeNode(Vector ** self);
void Vector_freeList(Vector ** self);
void Vector_print(Vector * self);
#endif