#include <iostream>
#include "Single.h"
#include "TextAnalyzer.h"

void
Single::Run(const std::vector<std::string> &files, const std::string &word) {
    TextAnalyzer::AnalyzeText(files, word);
    TextAnalyzer::PrintResult();
}
