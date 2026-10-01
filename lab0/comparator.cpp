#include "comparator.h"

bool compareWords(const std::pair<std::string, int> &p1,
                  const std::pair<std::string, int> &p2) {
    return p1.second > p2.second;
}
