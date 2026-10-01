#ifndef LAB0_WORD_COUNTER_H
#define LAB0_WORD_COUNTER_H

#include <string>
// #include <list>
#include <map>
// #include <vector>

class WordCounter {
    std::map<std::string, int> wordCounts;
    int totalWords = 0;
    std::string currWord;

    void buildWord(unsigned char c);

    void finalizeWord();

public:
    void addLine(std::string &line);

    void finishProcess();

    std::map<std::string, int> getWordCounts() const;

    int getTotalWords() const;
};

#endif
