#include <random>
#include <chrono>
#include <iostream>

// 通过rng() 生成随机数, 用于生成hash值，返回LL
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    for (int i = 0; i < 10; i++) {
        std::cout << rng() << " \n"[i == 9];
    }
    return 0;
}
