#include <stdlib.h>
#include <memory.h>
#include "nlp.h"
#include "storage.h"

Text * processText(Text * self);

int main(void) {
    const char * input = "tmp";
	const char * output = "out";

    Text * text = Storage_readText(input);
	 text = processText(text);
	Storage_writeResult(output, text);
    Text_free(&text);
	return EXIT_SUCCESS;
}

Text * processText(Text * self) {
	for (int i = 0; i < Text_countSentence(self); ++i) {
		Sentence * curSentence = Text_getSentence(self,i);
		for (int j = 0; j < Sentence_countWord(curSentence); ++j) {
			Word * curWord = Sentence_getWord(curSentence, j);
			if (!Word_isUnique(curSentence, curWord)) {
				char buffer[100] = "";
				Word_getString(curWord, buffer);
				curSentence = Sentence_deleteWord(curSentence, j);
				int index = Sentence_searchWord(curSentence, buffer);
				while (index != -1) {
					curSentence = Sentence_deleteWord(curSentence, index);
					index = Sentence_searchWord(curSentence, buffer);
				}
			}

		}

	}
	return self;
}

