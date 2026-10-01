#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <list>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "word_counter.h"
#include "comparator.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: file.exe <input file> <output file>" << std::endl;
        return 1;
    }

    std::ifstream inFile(argv[1]);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file " << argv[1] << std::endl;
        return 1;
    }

    WordCounter wordCounter;
    std::string line;
    while (std::getline(inFile, line)) {
        wordCounter.addLine(line);
    }
    wordCounter.finishProcess();

    auto wordCounts = wordCounter.getWordCounts();
    int totalWords = wordCounter.getTotalWords();

    std::vector<std::pair<std::string, int> > sortedWords(wordCounts.begin(), wordCounts.end());
    std::sort(sortedWords.begin(), sortedWords.end(), WordComparator());

    std::ofstream outFile(argv[2]);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file " << argv[2] << std::endl;
        return 1;
    }

    for (const auto &item: sortedWords) {
        double percent = 0.0;
        if (totalWords > 0) {
            percent = (item.second * 100.0) / totalWords;
        }
        outFile << item.first << ";" << item.second << ";"
                << std::fixed << std::setprecision(2) << percent << "%" << std::endl;
    }

    return 0;
}
