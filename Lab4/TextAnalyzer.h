#ifndef LAB4_TEXTANALYZER_H
#define LAB4_TEXTANALYZER_H

#include <utility>
#include <vector>
#include <string>
#include <map>

class TextAnalyzer {
public:
    TextAnalyzer(const std::vector<std::string> &file_names,
                 const std::string &target_word);

    void
    AnalyzeText(const std::vector<std::string> &file_names,
                const std::string &target_word);

    void
    InitializeMap();

    void
    PrintResult();

private:
    int
    GetWordCount(const std::string &file_name, const std::string &target_word);

    std::vector<std::string> file_names_;
    std::string target_word_;
    std::map<std::string, int> result_map_;
};


#endif //LAB4_TEXTANALYZER_H
