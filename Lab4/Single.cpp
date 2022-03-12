#include <iostream>
#include "Single.h"
#include "TextAnalyzer.h"

void
Single::Run(const std::vector<std::string> &files, const std::string &word) {
    TextAnalyzer textAnalyzer(files, word);
    textAnalyzer.InitializeMap();
    textAnalyzer.AnalyzeText(files, word);
}
