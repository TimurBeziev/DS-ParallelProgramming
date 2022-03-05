#include "TextAnalyzer.h"
#include <fstream>
#include <iostream>
#include <map>

std::map<std::string, int> result_map;

int GetWordCount(const std::string &file_name,
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

void TextAnalyzer::AnalyzeText(const std::string &file_name,
                               const std::string &target_word) {
    int count = GetWordCount(file_name, target_word);
    result_map[file_name] = count;
}

void TextAnalyzer::PrintResult() {
    for (const auto & el: result_map) {
        std::cout << el.first << "\t" << el.second << "\n";
    }
}



