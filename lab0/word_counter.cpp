#include "word_counter.h"
#include <cctype>

void WordCounter::buildWord(unsigned char c) {
    if (isalnum(c)) {
        currWord += tolower(c);
    } else {
        finalizeWord();
    }
}

void WordCounter::finalizeWord() {
    if (!currWord.empty()) {
        wordCounts[currWord] += 1;
        totalWords += 1;
        currWord.clear();
    }
}

void WordCounter::addLine(std::string &line) {
    for (char c: line) {
        buildWord(c);
    }
}

void WordCounter::finishProcess() {
    finalizeWord();
}

std::map<std::string, int> WordCounter::getWordCounts() const {
    return wordCounts;
}

int WordCounter::getTotalWords() const {
    return totalWords;
}
