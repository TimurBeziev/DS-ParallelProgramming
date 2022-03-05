#include "ParallelFirst.h"
#include <thread>
#include <utility>
#include <iostream>
#include "TextAnalyzer.h"

void ParallelFirst::Run(int th_num, const std::vector<std::string> &files,
                        std::string word) {
    std::thread myThreads[th_num];
    for (int i = 0; i < th_num; i++) {
        myThreads[i] = std::thread(TextAnalyzer::AnalyzeText, files[i], word);
    }
    for (int i = 0; i < th_num; i++) {
        myThreads[i].join();
    }
    TextAnalyzer::PrintResult();
}
