#include "Parallel.h"
#include <thread>
#include <stack>
#include <iostream>
#include "TextAnalyzer.h"


void Parallel::Run(const std::vector<std::string> &files,
                   std::string word, int th_num) {
    std::thread myThreads[th_num];
    std::vector<std::vector<std::string>> pulls(th_num);
    for (int i = 0; i < files.size(); i++) {
        pulls[i % th_num].push_back(files[i]);
    }
    TextAnalyzer textAnalyzer(files, word);
    textAnalyzer.InitializeMap();

    for (int i = 0; i < th_num; i++) {
        myThreads[i] = std::thread([&textAnalyzer](auto files, auto word) {
            textAnalyzer.AnalyzeText(files, word);
        }, pulls[i], word);
    }
    for (int i = 0; i < th_num; i++) {
        myThreads[i].join();
    }
    textAnalyzer.PrintResult();
}
