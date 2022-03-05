#include <iostream>
#include <thread>
#include <mutex>
#include <utility>
#include <vector>
#include <filesystem>
#include "ParallelFirst.h"
#include "Parallel.h"
#include "Single.h"

void GetFiles(std::vector<std::string> *file_names) {
    std::string path = "../TestSample/";
    for (const auto &entry: std::filesystem::directory_iterator(path)) {
        file_names->push_back(entry.path());
    }
}

int main() {
//    int n = 20;
    std::vector<std::string> file_names;
    GetFiles(&file_names);
//    Parallel::Run(file_names, "vitae", n);
    Single::Run(file_names, "apple");
    return 0;
}