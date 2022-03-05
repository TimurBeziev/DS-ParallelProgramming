#ifndef LAB4_PARALLELFIRST_H
#define LAB4_PARALLELFIRST_H

#include <vector>

class ParallelFirst {
public:
    static void
    Run(int th_num, const std::vector<std::string> &files, std::string word);
};

#endif //LAB4_PARALLELFIRST_H
