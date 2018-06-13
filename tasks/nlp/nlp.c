#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include "nlp.h"

struct Word {
	char wordbuff[STR_SIZE];
	Word * next;
};

struct Text {
    Sentence * sentence;
};

struct Sentence {
	Word * word;
	Sentence * next;
};




Text * Text_new(char * text) {
	Text * textPtr = (Text *)malloc(sizeof(Text));
	textPtr->sentence = Sentence_new();
	Sentence ** cur = &(textPtr->sentence);
	char buffer[100];
	buffer[0] = '\0';
	for (int i = 0; i < strlen(text); ++i) {
		if (isalpha(text[i]) || text[i] == '-') {
			sprintf(buffer + strlen(buffer),"%c", text[i]);
		}
		if ((isspace(text[i]) || text[i] == ',' || text[i] == '.' || text[i] == '!' || text[i] == '?') && isalpha(text[i - 1])) {
			Sentence_addWord(*cur, Word_new(buffer));
			buffer[0] = '\0';
		}
		if (i != 0 && (text[i - 1] == '.' || text[i - 1] == '!' || text[i - 1] == '?')) {
			Text_addSentence(textPtr, Sentence_new());
			cur = &((*cur)->next);
		}
	}
	return textPtr;
}

void  Text_addSentence(Text * self, Sentence * node) {
	if (NULL == self) {
		return;
	}

	if (NULL == self->sentence) {
		self->sentence = node;
		return;
	}

	Sentence * cur = self->sentence;
	while (cur->next != NULL) {
		cur = cur->next;
	}

	cur->next = node;
}

int Text_countSentence(Text * self) {
	int size = 0;

	if (NULL == self) {
		return size;
	}

	Sentence * cur = self->sentence;
	while (cur != NULL) {
		cur = cur->next;
		size++;
	}
	return size;
}

Sentence * Text_getSentence(Text * self, int index) {
	if (index >= Text_countSentence(self) || index < 0 || self == NULL) {
		return NULL;
	}

	Sentence * cur = self->sentence;

	while (index != 0) {
		cur = cur->next;
		index--;
	}

	return cur;
}

void Text_free(Text ** selfPtr) {
	int size = Text_countSentence(*selfPtr) - 1;
	while (size >= 0) {
		Text_deleteSentence(*selfPtr, size);
		size--;
	}
	free(*selfPtr);
	*selfPtr = NULL;
}

Text * Text_deleteSentence(Text * self, int index) {
	if (index >= Text_countSentence(self) || index < 0 || self == NULL) {
		return NULL;
	}
	if (index == 0) {
		Sentence * cur = self->sentence;
		self->sentence = self->sentence->next;
		Sentence_free(&cur);
		return self;
	}
	Sentence * cur = self->sentence;

	while (index - 1 != 0) {
		cur = cur->next;
		index--;
	}
	Sentence * buf = cur->next;
	cur->next = cur->next->next;
	Sentence_free(&buf);
	return self;
}








Sentence * Sentence_new(void) {
	Sentence * self = malloc(sizeof(Sentence));
	self->next = NULL;
	self->word = NULL;
	return self;
}

void Sentence_addWord(Sentence * self, Word * node) {
	if (NULL == self) {
		return;
	}

	if (NULL == self->word) {
		self->word = node;
		return;
	}

	Word * cur = self->word;
	while (cur->next != NULL) {
		cur = cur->next;
	}

	cur->next = node;
}

int Sentence_countWord(Sentence * self) {
	int size = 0;

	if (NULL == self) {
		return size;
	}

	Word * cur = self->word;
	while (cur != NULL) {
		cur = cur->next;
		size++;
	}
	return size;
}

Word * Sentence_getWord(Sentence * self, int index) {
	if (index >= Sentence_countWord(self) || index < 0 || self == NULL) {
		return NULL;
	}
	if (index == 0) {
		return self->word;
	}
	Word * cur = self->word;

	while (index != 0) {
		cur = cur->next;
		index--;
	}

	return cur;
}

void Sentence_free(Sentence ** selfPtr) {
	int size = Sentence_countWord(*selfPtr) - 1;
	while (size >= 0) {
		Sentence_deleteWord(*selfPtr, size);
		size--;
	}
	free(*selfPtr);
	*selfPtr = NULL;
}

Sentence * Sentence_deleteWord(Sentence * self, int index) {
	if (index >= Sentence_countWord(self) || index < 0 || self == NULL) {
		return NULL;
	}
	if (index == 0) {
		Word * buf = self->word;
		self->word = self->word->next;
		Word_free(&buf);
		return self;
	}
	Word * cur = self->word;

	while (index - 1 != 0) {
		cur = cur->next;
		index--;
	}
	Word * buf = cur->next;
	cur->next = cur->next->next;
	Word_free(&buf);
	return self;
}

int Sentence_searchWord(Sentence * self, char * wordString) {
	if (self == NULL || self->word == NULL) {
		return -1;
	}
	int index = 0;
	Word * cur = self->word;
	while (cur != NULL) {
		if (!strcmp(cur->wordbuff, wordString)) {
			return index;
		}
		cur = cur->next;
		index ++;
	}
	return -1;
}






Word * Word_new(char * word) {
	Word * self = malloc(sizeof(Word));
	self->next = NULL;
	strcpy(self->wordbuff, word);
	return self;
}

void Word_free(Word ** selfPtr) {
	free(*selfPtr);
	*selfPtr = NULL;
}

char * Word_getString(Word * self, char * buffer) {
	strcpy(buffer, self->wordbuff);
	return buffer;
}

bool Word_isUnique(Sentence * self, Word * word) {
	Word * cur = self->word;
	int count = 0;
	for (int i = 0; i < Sentence_countWord(self); ++i) {
		if (!strcmp(word->wordbuff, cur->wordbuff)) {
			count++;
			if (count == 2) {
				return false;
			}
		}
		cur = cur->next;
	}
	return true;
}





void _printText(Text * self) {
	Sentence * curSentence = self->sentence;
	while (curSentence != NULL) {
		Word * curWord = curSentence->word;
		while (curWord != NULL) {
			printf("%s, ", curWord->wordbuff);
			curWord = curWord->next;
		}
		puts("");
		curSentence = curSentence->next;
	}
}













