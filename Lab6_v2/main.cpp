#include <iostream>
#include "DefiniteIntegral.h"

int main() {
    auto integral1 = DefiniteIntegral(0, 2, [](double x) {
        return x;
    });

    std::cout << integral1.Parallel(3., 1);
    return 0;
}
