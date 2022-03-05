#include "TextAnalyzer.h"
#include <fstream>
#include <iostream>

int TextAnalyzer::GetWordCount(const std::string &file_name,
                               const std::string &target_word) {
    std::ifstream fin(file_name);
    std::string word;
    int count = 0;
    while (!fin.eof()) {
        fin >> word;
        if (word == target_word) {
            count++;
        }
    }
    return count;
}
