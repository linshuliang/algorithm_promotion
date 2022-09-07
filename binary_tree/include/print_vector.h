#ifndef PRINT_VECTOR_H
#define PRINT_VECTOR_H

#include <iostream>
#include <vector>

const int COUNT = 10;

template <typename T>
void print(const std::vector<T>& nums) {
    int count = 0;
    for (auto& n : nums) {
        std::cout << n << " ";
        count++;
        if (count == COUNT) {
            std::cout << std::endl;
            count = 0;
        }
    }

    if (count)
        std::cout << std::endl;
}

template <typename T>
void print(const std::vector<std::vector<T>>& nums) {
    for (const std::vector<T>& rows : nums) {
        for (const auto& n : rows) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
}

#endif