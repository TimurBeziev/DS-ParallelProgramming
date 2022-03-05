#include "ParallelFirst.h"
#include <thread>
#include "TextAnalyzer.h"

void
ParallelFirst::Run(const std::vector<std::string> &files, std::string word) {
    int th_num = files.size();
    std::thread myThreads[th_num];
    for (int i = 0; i < th_num; i++) {
        myThreads[i] = std::thread(TextAnalyzer::AnalyzeText,
                                   std::vector<std::string>({files[i]}),
                                   word);
    }
    for (int i = 0; i < th_num; i++) {
        myThreads[i].join();
    }
    TextAnalyzer::PrintResult();
}
