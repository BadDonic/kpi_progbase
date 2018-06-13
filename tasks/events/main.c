#include <stdio.h>
#include <events.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <pbconsole.h>

typedef struct Human Human;
typedef struct Room Room;

enum {
	RandomIndexEventTypeId,
	InsideRoomEventTypeId,
	OutsideRoomEventTypeId,
	KeyInputEventTypeId,
	SwitchOnEventTypeId,
	SwitchOffEventTypeId
};

struct Human {
	char name[100];
	Human * next;
};

struct Room {
	Human * inside;
	Human * outside;
};

void UpdatePrintHandler_update(EventHandler * self, Event * event);
void RandomIndexGenerator_update(EventHandler * self, Event * event);
void CustomHandler_update(EventHandler * self, Event * event);
void MovementPeopleHandler_update(EventHandler * self, Event * event);

Human * Human_new(char * name);
void Human_free(Human ** self);
void Human_addLast(Human ** self, Human * node);
Human * Human_deleteNode(Human ** self, int index);
Human * Human_getStructure(Human * self, int index);
int Human_countList(Human * self);
void Room_free(void * ptr);


int main(void) {

	EventSystem_init();

	EventSystem_addHandler(EventHandler_new(NULL, NULL, UpdatePrintHandler_update));
	EventSystem_addHandler(EventHandler_new(NULL, NULL, RandomIndexGenerator_update));


	Room * flat = malloc(sizeof(Room));
	flat->outside = NULL;
	Human_addLast(&(flat->outside), Human_new("Taras"));
	Human_addLast(&(flat->outside), Human_new("Vlad"));
	Human_addLast(&(flat->outside), Human_new("Lena"));
	flat->inside = NULL;
	EventSystem_addHandler(EventHandler_new(flat, Room_free, MovementPeopleHandler_update));
	EventSystem_addHandler(EventHandler_new(NULL, NULL, CustomHandler_update));

	EventSystem_loop();
	EventSystem_cleanup();

	return 0;
}

void RandomIndexGenerator_update(EventHandler * self, Event * event) {
	switch (event->type) {
		case StartEventTypeId: {
			srand((unsigned int)time(0));
			break;
		}
		case UpdateEventTypeId: {
			if (rand() % 33 == 0) {
				int * number = malloc(sizeof(int));
				*number = abs(rand() % 3);
				EventSystem_raiseEvent(Event_new(self, RandomIndexEventTypeId, number, free));
			}
			break;
		}
		default:
			break;
	}
}

void MovementPeopleHandler_update(EventHandler * self, Event * event) {
	if (event->type == RandomIndexEventTypeId) {
		Room * temp = (Room *)self->data;
		int index = *(int *)event->data;
		Human * buffer = NULL;
		int id = 0;
		if ((Human_countList(temp->outside) != 0  && Human_countList(temp->outside) <= index) || Human_countList(temp->outside) == 0) {
			index -= Human_countList(temp->outside);
			buffer = Human_deleteNode(&(temp->inside), index);
			Human_addLast(&(temp->outside), buffer);
			id = OutsideRoomEventTypeId;
			buffer = temp->outside;
		}else {
			buffer = Human_deleteNode(&(temp->outside), index);
			id = InsideRoomEventTypeId;
			Human_addLast(&(temp->inside), buffer);
			buffer = temp->inside;
		}
		EventSystem_raiseEvent(Event_new(self, id, buffer, NULL));
		return;
	}else if (conIsKeyDown()) {
		char * keyCode = malloc(sizeof(char));
		*keyCode = (char)getchar();
		EventSystem_raiseEvent(Event_new(self, KeyInputEventTypeId, keyCode, free));
	}
}

void CustomHandler_update(EventHandler * self, Event * event) {
	switch (event->type) {
		case InsideRoomEventTypeId: {
			if (Human_countList((Human *)event->data) == 1)
				EventSystem_raiseEvent(Event_new(self, SwitchOnEventTypeId, NULL, NULL));
			break;
		}
		case OutsideRoomEventTypeId: {
			if (Human_countList((Human *)event->data) == 3)
				EventSystem_raiseEvent(Event_new(self, SwitchOffEventTypeId, NULL, NULL));
			break;
		}
		case KeyInputEventTypeId: {
			char * keyCodePtr = (char *)event->data;
			char keyCode = *keyCodePtr;
			if (keyCode == 'q')
				EventSystem_exit();
			break;
		}
		default:
			break;
	}
}

void UpdatePrintHandler_update(EventHandler * self, Event * event) {
	switch (event->type) {
		case StartEventTypeId: {
			puts("");
			puts("<<<START!>>>");
			puts("");
			break;
		}
		case ExitEventTypeId: {
			puts("");
			puts("<<<EXIT!>>>");
			puts("");
			break;
		}
		case OutsideRoomEventTypeId: {
			Human * buffer = Human_getStructure((Human *)event->data, Human_countList((Human *)event->data) - 1);
			printf("%s \t(left)\t this room\n", buffer->name);
			break;
		}
		case InsideRoomEventTypeId: {
			Human * buffer = Human_getStructure((Human *)event->data, Human_countList((Human *)event->data) - 1);
			printf("%s \t(went)\t into this room\n", buffer->name);
			break;
		}
		case SwitchOnEventTypeId: {
			printf("SWITCH \t\t<<ON>>\t\t THE LIGHT\n\n");
			break;
		}
		case SwitchOffEventTypeId: {
			printf("SWITCH \t\t<<OFF>>\t\t THE LIGHT\n\n");
			break;
		}
		default:
			break;
	}
}

void Human_addLast(Human ** self, Human *node) {
	if (*self == NULL) {
		*self = node;
		return;
	}

	Human * current = *self;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = node;
}

void Room_free(void * ptr) {
	Room * self = (Room *)ptr;
	for (int i = Human_countList((self)->inside) - 1; i >= 0; --i) {
		Human * cur = Human_deleteNode(&((self)->inside), i);
		Human_free(&cur);
	}
	for (int i = Human_countList((self)->outside) - 1; i >= 0; --i) {
		Human * cur = Human_deleteNode(&((self)->outside), i);
		Human_free(&cur);
	}
	free(self);
}

Human * Human_deleteNode(Human **self, int index) {
	if (index >= Human_countList(*self) || index < 0) {
		return NULL;
	}
	Human * current = *self;
	if (index == 0) {
		*self = (*self)->next;
		current->next = NULL;
		return current;
	}
	while (index - 1 != 0) {
		current = current->next;
		index--;
	}
	Human * temp = current->next;
	current->next = current->next->next;
	temp->next = NULL;
	return temp;
}

int Human_countList(Human *self) {
	int count = 0;
	while (self != NULL) {
		self = self->next;
		count++;
	}
	return count;
}

void Human_free(Human **self) {
	free(*self);
	*self = NULL;
}

Human * Human_new(char *name) {
	Human * self = malloc(sizeof(Human));
	strcpy(self->name, name);
	self->next = NULL;
	return self;
}

Human *Human_getStructure(Human *self, int index) {
	if (index >= Human_countList(self) || index < 0) {
		return NULL;
	}
	while (self != NULL && index != 0) {
		self = self->next;
		index--;
	}
	return self;
}
