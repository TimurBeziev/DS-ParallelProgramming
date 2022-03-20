#ifndef LAB6_V2_DEFINITEINTEGRAL_H
#define LAB6_V2_DEFINITEINTEGRAL_H

#include <functional>
#include <atomic>
#include <thread>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>

class DefiniteIntegral {
    using Func = std::function<double(double)>;

public:
    DefiniteIntegral() = delete;

    DefiniteIntegral(double l, double r, const Func &func) : l_(l), r_(r), func_(func) {}

    void Calculate(double l, double r, double step, const Func &func, std::vector<double> &results, int i) {
        while (l < r) {
            results[i] += func(l) * step;
            l += step;
        }
    }

    double Parallel(double step, int th_num) {
        double interval = (r_ - l_) / th_num;
        if (interval < step) {
            return 0;
        }
        std::vector<double> results(th_num, 0);
        std::thread myThreads[th_num];

        for (int i = 0; i < th_num; i++) {
            double l = l_ + interval * i;
            double r = std::min(r_, l + interval);
            myThreads[i] = std::thread([l, r, step, i, &results, this]() {
                Calculate(l, r, step, func_, results, i);
            });
        }
        for (int i = 0; i < th_num; i++) {
            myThreads[i].join();
        }

        return std::accumulate(results.begin(), results.end(), 0.);
    }

private:
    double l_;
    double r_;
    Func func_;
};


#endif //LAB6_V2_DEFINITEINTEGRAL_H
