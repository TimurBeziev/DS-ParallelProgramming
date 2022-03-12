#include <iostream>
#include <thread>
#include <mutex>
#include <utility>
#include <vector>
#include <filesystem>
#include "Single.h"
#include "Parallel.h"

void GetFiles(std::vector<std::string> *file_names) {
    std::string path = "../TestSample/";
    for (const auto &entry: std::filesystem::directory_iterator(path)) {
        file_names->push_back(entry.path());
    }
}

int main() {
    int n = 20;
    std::vector<std::string> file_names;
    GetFiles(&file_names);
    Parallel parallel;
    parallel.Run(file_names, "vitae", n);
//    Single single;
//    single.Run(file_names, "apple");
    return 0;
}