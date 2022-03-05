#include <iostream>
#include <thread>
#include <mutex>
#include <utility>
#include <vector>
#include "ParallelFirst.h"


int main() {
    int n = 2;
    std::vector<std::string> file_names = {"1.txt", "2.txt"};
    ParallelFirst::Run(n, file_names, "hello");
    return 0;
}