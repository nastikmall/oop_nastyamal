#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <list>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "comparator.h"
#include "word_counter.h"

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

    std::ofstream outFile(argv[2]);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file " << argv[2] << std::endl;
        return 1;
    }

    std::list<std::string> lines;
    std::string line;
    while (getline(inFile, line)) {
        lines.push_back(line);
    }

    WordCountRes res = countWords(lines);

    std::vector<std::pair<std::string, int> > sortedWords;
    for (const auto &item: res.wordCounts) {
        sortedWords.push_back(item);
    }

    sort(sortedWords.begin(), sortedWords.end(), compareWords);

    for (const auto &item: sortedWords) {
        double percent = 0.0;
        if (res.totalWords > 0) {
            percent = (item.second * 100.0) / res.totalWords;
        }
        outFile << item.first << ";" << item.second << ";"
                << std::fixed << std::setprecision(2) << percent << "%" << std::endl;
    }

    return 0;
}
