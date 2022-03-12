#ifndef LAB4_PARALLEL_H
#define LAB4_PARALLEL_H

#include <vector>

class Parallel {
public:
    void
    Run(const std::vector<std::string> &files, std::string word, int th_num);
};


#endif //LAB4_PARALLEL_H
