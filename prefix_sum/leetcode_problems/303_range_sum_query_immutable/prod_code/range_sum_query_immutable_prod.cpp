#include "num_array.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <vector>

void testLeetCodeExample() {
    const std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    const NumArray numArray(nums);

    assert(numArray.sumRange(0, 2) == 1);
    assert(numArray.sumRange(2, 5) == -1);
    assert(numArray.sumRange(0, 5) == -3);
}

void testSingleElement() {
    const std::vector<int> nums = {10};
    const NumArray numArray(nums);

    assert(numArray.sumRange(0, 0) == 10);
}

void testAllPositiveNumbers() {
    const std::vector<int> nums = {1, 2, 3, 4, 5};
    const NumArray numArray(nums);

    assert(numArray.sumRange(0, 4) == 15);
    assert(numArray.sumRange(1, 3) == 9);
    assert(numArray.sumRange(2, 2) == 3);
}

void testAllNegativeNumbers() {
    const std::vector<int> nums = {-1, -2, -3, -4};
    const NumArray numArray(nums);

    assert(numArray.sumRange(0, 3) == -10);
    assert(numArray.sumRange(1, 2) == -5);
}

void testInvalidRange() {
    const std::vector<int> nums = {1, 2, 3};
    const NumArray numArray(nums);

    bool exceptionThrown = false;

    try {
        numArray.sumRange(-1, 2);
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);
}

void testEmptyInput() {
    bool exceptionThrown = false;

    try {
        const std::vector<int> nums = {};
        const NumArray numArray(nums);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);
}

void testFullFlow() {
    const std::vector<int> nums = {5, -2, 3, 10, -1};
    const NumArray numArray(nums);

    assert(numArray.sumRange(0, 0) == 5);
    assert(numArray.sumRange(0, 2) == 6);
    assert(numArray.sumRange(1, 3) == 11);
    assert(numArray.sumRange(0, 4) == 15);
}

int main() {
    testLeetCodeExample();
    testSingleElement();
    testAllPositiveNumbers();
    testAllNegativeNumbers();
    testInvalidRange();
    testEmptyInput();
    testFullFlow();

    std::cout << "All tests passed successfully.\n";

    return 0;
}