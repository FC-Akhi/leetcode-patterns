/* 
* Title: contiguous_array_v2
*
* Description: 
* This program implements LeetCode 525: Contiguous Array.
* It takes an input binary vector containing only 0s and 1s.
*
* The goal is to find the maximum length of a contiguous subarray
* that contains an equal number of 0s and 1s.
*
* Convert the binary array into a balance array:
*      - 0 becomes -1
*      - 1 becomes +1
*
* Build a prefix sum array from the balance array.
* Store all indices for each prefix sum value using a map in key-value pair
* Where key is the unique prefix sum and values are the indices where particular 
* value appeares
* For each prefix sum value, take the first and last index where it appears.
* The difference between them gives the longest subarray length
* for that prefix sum, where the subarray has equal number of 
* 0s and 1s.
*
* Return the maximum length found.
*
*
* Main Improvements:
* 1. Implements Prefix sum approach and  std::map
*
* Approach:
* Prefix sum construction (bruteforce)
*
* Author: F.C.Fahi 
* Date: 08 July 2026 
*/


#include<iostream>
#include<stdio.h>
#include<vector>
#include<unordered_map>
#include <cassert>
#include <stdexcept>

class Solution {
public:

    // Solution(){};


    // Generate balance array
    std::vector<int> getBalanceArray(std::vector<int>& nums, int n) {

        // Declare empty vector for balance array
        std::vector<int> balance_array(n);

        // Generate balance array
        for(int i = 0; i < n; i++) {
            if (nums[i] == 0) 
                balance_array[i] = -1;
            else if (nums[i] == 1)
                balance_array[i] = 1;
            else
                throw std::invalid_argument("Input vector must contain 0s and 1s");
        }

        return balance_array;

    }

    // Get prefix sum
    std::vector<int> getPrefixSum(std::vector<int> balanceArray, int n) {


        std::vector<int> prefix_sum(n);

        // Before taking any element, prefix_sum[0] is 0
        prefix_sum[0] = 0;
        prefix_sum[1] = balanceArray[0];

        // Build prefix sum array
        for (int i = 2; i < n; i++) {
            prefix_sum[i] = prefix_sum[i-1] + balanceArray[i-1];
        }

        return prefix_sum;

    }



    // Get the maximum length of contiguous subarray of 0s and 1s
    int findMaxLength(std::vector<int>& nums) {

        if (nums.empty())
            throw std::invalid_argument("Input vector must not be empty");



        // Get the sise of input nums
        int n = nums.size();

        // Declare empty vector for balance array
        std::vector<int> balance_array(n);

        // Get balance array
        balance_array = getBalanceArray(nums, n);


        // prefix_sum will store running sums
        // Size is n + 1 because prefix_sum[0] = 0
        std::vector<int> prefix_sum(n+1);
        
        // Get prefix sum array
        prefix_sum = getPrefixSum(balance_array, n+1);

        // Map each prefix sum value to all indices where it appears
        // key   = prefix sum value
        // value = list of indices where this prefix sum appears
        std::unordered_map<int, std::vector<int>> map_value_indices;

        for(int i = 0; i < (n+1); i++) {

            map_value_indices[prefix_sum[i]].push_back(i);

        }
        
        // max_length stores the final answer
        int max_length = 0;

        // length stores current possible subarray length
        int length = 0;

        for(const auto& pair : map_value_indices) {

            // indices contains all positions where this prefix sum appeared
            const std::vector<int>& indices = pair.second;

            // First occurrence of this prefix sum
            int first = indices.front();

            // Last occurrence of this prefix sum
            int last = indices.back();

            // Difference gives length of balanced subarray
            length = last - first;

            // Update maximum length if current length is bigger
            if (max_length < length) 
                max_length = length;
            
        }
        
        // Return the maximum length found
        return max_length;



    }
};


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
