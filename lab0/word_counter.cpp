#include "word_counter.h"
#include <cctype>

WordCountRes countWords(const std::list<std::string> &lines) {
    WordCountRes res;
    res.totalWords = 0;

    std::string currWord;

    for (const std::string &currLine: lines) {
        for (unsigned char c: currLine) {
            if (isalnum(c)) {
                currWord += tolower(c);
            } else {
                if (currWord.length() != 0) {
                    res.wordCounts[currWord]++;
                    res.totalWords++;
                    currWord.clear();
                }
            }
        }
    }
    if (currWord.length() != 0) {
        res.wordCounts[currWord]++;
        res.totalWords++;
        currWord.clear();
    }

    return res;
}
