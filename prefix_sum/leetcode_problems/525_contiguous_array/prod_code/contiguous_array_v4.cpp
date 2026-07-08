#include "contiguous_array.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <vector>


// Unit testing
void testLeetCodeExample() {

    Solution test;

    std::vector<int> nums_1 = {0, 1};
    assert(test.findMaxLength(nums_1) == 2);

    std::vector<int> nums_2 = {0, 1, 0};
    assert(test.findMaxLength(nums_2) == 2);

    std::vector<int> nums_3 = {0, 1, 1, 1, 1, 1, 0, 0, 0};
    assert(test.findMaxLength(nums_3) == 6);
}


void testSingleElement() {

    Solution test;

    std::vector<int> nums = {1};
    assert(test.findMaxLength(nums) == 0);
}

void testAllSameValues() {

    Solution test;

    std::vector<int> nums_1 = {0, 0};
    assert(test.findMaxLength(nums_1) == 0);

    std::vector<int> nums_2 = {1, 1, 1};
    assert(test.findMaxLength(nums_2) == 0);
}



void testDecimalValues() {

    Solution test;

    std::vector<int> nums = {10, -2, 5, -4, 6};
    
    bool exceptionThrown = false;

    try {
        test.findMaxLength(nums);
    } catch (const std::invalid_argument& e) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);
}


void testEmptyInput() {

    Solution test;
    
    bool exceptionThrown = false;

    try {
        std::vector<int> nums = {};
        test.findMaxLength(nums);

    } catch (const std::invalid_argument& e){
        exceptionThrown = true;
    }

    assert(exceptionThrown);
}



int main() {

    testLeetCodeExample();
    testSingleElement();
    testAllSameValues();
    testDecimalValues();
    testEmptyInput();


    std::cout << "All tests passed successfully.\n";
    
}
