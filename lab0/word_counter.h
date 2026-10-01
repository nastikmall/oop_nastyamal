#ifndef LAB0_WORD_COUNTER_H
#define LAB0_WORD_COUNTER_H

#include <string>
#include <list>
#include <map>

struct WordCountRes {
    std::map<std::string, int> wordCounts;
    int totalWords;
};

WordCountRes countWords(const std::list<std::string> &lines);

#endif //LAB0_WORD_COUNTER_H
