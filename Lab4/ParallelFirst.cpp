#include "ParallelFirst.h"
#include <thread>
#include <mutex>
#include <utility>
#include <iostream>
#include "TextAnalyzer.h"

//std::mutex g_lock;

void AnalyzeText(const std::string &file_name, const std::string &target_word) {
    int count = TextAnalyzer::GetWordCount(file_name, target_word);
    std::cout << "Count in:\t" << file_name << "\t"
              << count << "\n";
}

void ParallelFirst::Run(int th_num, const std::vector<std::string> &files,
                        std::string word) {
    std::thread myThreads[th_num];
    for (int i = 0; i < th_num; i++) {
        myThreads[i] = std::thread(AnalyzeText, files[i], word);
    }
    for (int i = 0; i < th_num; i++) {
        myThreads[i].join();
    }
}
