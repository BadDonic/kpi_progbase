#include <vector.h>
#include <stdlib.h>
#include <stdio.h>

Vector * Vector_new(int number) {
	Vector * self = malloc(sizeof(Vector));
	self->number = number;
	self->next = NULL;
	return self;
}

void Vector_addLast(Vector ** self, Vector * node) {
	if (node == NULL) return;
	if (*self == NULL) {
		*self = node;
		return;
	}
	Vector * current = *self;
	while (current->next != NULL) current = current->next;

	current->next = node;
}

void Vector_freeNode(Vector ** self) {
	free(*self);
	*self = NULL;
}

void Vector_freeList(Vector ** self) {
	while ((*self)->next != NULL) {
		Vector * current = *self;
		while (current->next->next != NULL) {
			current = current->next;
		}
		Vector_freeNode(&(current->next));
	}
	Vector_freeNode(self);
}

void Vector_print(Vector * self) {
	printf("Vector : { ");
	while (self != NULL) {
		printf("%i ", self->number);
		self = self->next;
	}
	puts("}");
}

