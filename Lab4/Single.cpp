#include <iostream>
#include "Single.h"
#include "TextAnalyzer.h"

void
Single::Run(const std::vector<std::string> &files, const std::string &word) {
    for (const auto &file: files) {
        TextAnalyzer::AnalyzeText(file, word);
    }
    TextAnalyzer::PrintResult();
}
