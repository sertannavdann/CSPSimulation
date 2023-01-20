#include <iostream>
#include <random>

int main() {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<int> dist(0, 6);

    for (int i = 0; i < 10; i++) {
        std::cout << dist(rng) << ' ';
    }
    return 0;
}