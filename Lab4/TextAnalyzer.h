#ifndef LAB4_TEXTANALYZER_H
#define LAB4_TEXTANALYZER_H

#include <utility>
#include <vector>
#include <string>

class TextAnalyzer {
public:
    static int
    GetWordCount(const std::string &file_name, const std::string &target_word);
};


#endif //LAB4_TEXTANALYZER_H
