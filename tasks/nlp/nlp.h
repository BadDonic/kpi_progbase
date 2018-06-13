#ifndef NLP_NLP_H
#define NLP_NLP_H

#include <stdbool.h>

enum {STR_SIZE = 100000};

typedef struct Text Text;
typedef struct Sentence Sentence;
typedef struct Word Word;



Text *  Text_new(char * text);
void  Text_addSentence(Text * self, Sentence * node);
void Text_free(Text ** selfPtr);
int Text_countSentence(Text * self);
Sentence * Text_getSentence(Text * self, int index);
Text * Text_deleteSentence(Text * self, int index);

Sentence * Sentence_new(void);
void Sentence_addWord(Sentence * self, Word * node);
void Sentence_free(Sentence ** selfPtr);
int Sentence_countWord(Sentence * self);
Word * Sentence_getWord(Sentence * self, int index);
Sentence * Sentence_deleteWord(Sentence * self, int index);
int Sentence_searchWord(Sentence * self, char * wordString);


Word * Word_new(char * word);
void Word_free(Word ** selfPtr);
char * Word_getString(Word * self, char * buffer);
bool Word_isUnique(Sentence * self, Word * word);


void _printText(Text * self);

#endif
