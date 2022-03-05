#ifndef LAB4_TEXTANALYZER_H
#define LAB4_TEXTANALYZER_H

#include <utility>
#include <vector>
#include <string>
#include <map>

class TextAnalyzer {
public:
    static void
    AnalyzeText(const std::vector<std::string> &file_names,
                const std::string &target_word);

    static void
    InitializeMap(const std::vector<std::string> &file_names);

    static void
    PrintResult();
};


#endif //LAB4_TEXTANALYZER_H
