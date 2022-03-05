#include "TextAnalyzer.h"
#include <fstream>
#include <iostream>
#include <map>

std::map<std::string, int> result_map;

int GetWordCount(const std::string &file_name, const std::string &target_word) {
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

void TextAnalyzer::AnalyzeText(const std::vector<std::string> &file_names,
                               const std::string &target_word) {
    for (const auto &el: file_names) {
        int count = GetWordCount(el, target_word);
        result_map[el] = count;
    }
}

void TextAnalyzer::PrintResult() {
    for (const auto &el: result_map) {
        std::cout << el.first << "\t" << el.second << "\n";
    }
}

void TextAnalyzer::InitializeMap(const std::vector<std::string> &file_names) {
    for (const auto &el: file_names) {
        result_map[el] = 0;
    }
}



