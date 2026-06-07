/*
 * Title: Range Sum Query - Immutable
 *
 * Description:
 * This code implements the NumArray class using the prefix sum technique.
 * The constructor builds the prefix sum vector once.
 * The sumRange() method answers each range query in O(1) time.
 *
 * This version is written as a simple industry-style development version:
 * - no manual user input
 * - no debug flag
 * - no mixed printf/cin style
 * - prefix sum is stored inside the class
 * - tests are repeatable using assert()
 *
 *
 * Author: F.C.Fahi
 * Date: 07 June 2026
 */

// #define NDEBUG
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <vector>

class NumArray {
private:
    std::vector<int> prefixSum;

public:
    /*
    * Constructor: NumArray
    *
    * Description:
    * Builds the prefix sum vector from the input vector.
    *
    * Input:
    * nums = input vector
    *
    * Example:
    * nums      = [-2, 0, 3, -5, 2, -1]
    * prefixSum = [-2, -2, 1, -4, -2, -3]
    */
    explicit NumArray(const std::vector<int>& nums) {
        if (nums.empty()) {
            throw std::invalid_argument("Input vector cannot be empty");
        }

        prefixSum.resize(nums.size());

        prefixSum[0] = nums[0];

        for (int i = 1; i < static_cast<int>(nums.size()); i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
    }

    /*
    * Method: sumRange
    *
    * Description:
    * Returns the sum of elements from index left to index right.
    * Both left and right are included.
    *
    * Input:
    * left  = starting index
    * right = ending index
    *
    * Output:
    * Integer range sum
    */
    int sumRange(int left, int right) const {
        if (left < 0 || left > right || right >= static_cast<int>(prefixSum.size())) {
            throw std::out_of_range("Invalid range index");
        }

        if (left == 0) {
            return prefixSum[right];
        }

        return prefixSum[right] - prefixSum[left - 1];
    }
};

/*
* Unit Test: Basic LeetCode example
*/
void testLeetCodeExample() {
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};

    NumArray numArray(nums);

    assert(numArray.sumRange(0, 2) == 1);
    assert(numArray.sumRange(2, 5) == -1);
    assert(numArray.sumRange(0, 5) == -3);
}

/*
* Unit Test: Single element vector
*/
void testSingleElement() {
    std::vector<int> nums = {10};

    NumArray numArray(nums);

    assert(numArray.sumRange(0, 0) == 10);
}

/*
* Unit Test: All positive numbers
*/
void testAllPositiveNumbers() {
    std::vector<int> nums = {1, 2, 3, 4, 5};

    NumArray numArray(nums);

    assert(numArray.sumRange(0, 4) == 15);
    assert(numArray.sumRange(1, 3) == 9);
    assert(numArray.sumRange(2, 2) == 3);
}

/*
* Unit Test: All negative numbers
*/
void testAllNegativeNumbers() {
    std::vector<int> nums = {-1, -2, -3, -4};

    NumArray numArray(nums);

    assert(numArray.sumRange(0, 3) == -10);
    assert(numArray.sumRange(1, 2) == -5);
}

/*
* Unit Test: Invalid range
* This test checks:
* When an invalid range is given, does sumRange() throw an out_of_range exception?
*/
void testInvalidRange() {
    std::vector<int> nums = {1, 2, 3};

    NumArray numArray(nums);

    bool exceptionThrown = false;

    try {
        numArray.sumRange(-1, 2);
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }

    // Yes it will be true and continue next. If this test gives false it would stuck
    assert(exceptionThrown == true);
}

/*
* Integration Test:
* Tests the full flow:
* input vector -> NumArray object -> prefix sum internally -> multiple queries
*/
void testFullFlow() {
    std::vector<int> nums = {5, -2, 3, 10, -1};

    NumArray numArray(nums);

    std::vector<int> results;

    results.push_back(numArray.sumRange(0, 0));
    results.push_back(numArray.sumRange(0, 2));
    results.push_back(numArray.sumRange(1, 3));
    results.push_back(numArray.sumRange(0, 4));

    assert(results[0] == 5);
    assert(results[1] == 6);
    assert(results[2] == 11);
    assert(results[3] == 15);
}

int main() {
    testLeetCodeExample();
    testSingleElement();
    testAllPositiveNumbers();
    testAllNegativeNumbers();
    testInvalidRange();
    testFullFlow();

    std::cout << "All tests passed successfully.\n";

    return 0;
}