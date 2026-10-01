#ifndef LAB0_COMPARATOR_H
#define LAB0_COMPARATOR_H

#include <string>
#include <utility>

class WordComparator {
public:
    bool operator()(const std::pair<std::string, int> &p1,
                    const std::pair<std::string, int> &p2) const {
        return p1.second > p2.second;
    }
};

#endif
