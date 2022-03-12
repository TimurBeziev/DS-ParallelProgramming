#include "TextAnalyzer.h"
#include <fstream>
#include <iostream>
#include <map>


void TextAnalyzer::AnalyzeText(const std::vector<std::string> &file_names,
                               const std::string &target_word) {
    for (const auto &el: file_names) {
        int count = GetWordCount(el, target_word);
        result_map_[el] = count;
    }
}

void TextAnalyzer::InitializeMap() {
    for (const auto &el: file_names_) {
        result_map_[el] = 0;
    }
}

TextAnalyzer::TextAnalyzer(const std::vector<std::string> &file_names,
                           const std::string &target_word) {
    file_names_ = file_names;
    target_word_ = target_word;
}

void TextAnalyzer::PrintResult() {
    for (const auto &el: result_map_) {
        std::cout << el.first << "\t" << el.second << "\n";
    }
}

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



