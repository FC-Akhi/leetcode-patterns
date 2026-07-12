/* 
* Title: contiguous_array_v2
* Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
* A subarray is a contiguous non-empty sequence of elements within an array.
*
* Main Improvements:
* Prefix sum and hash map
* Approach:
* Prefix sum and hash map
*
* Author: F.C.Fahi 
* Date: 11 July 2026 
*/

#include <vector>
#include <unordered_map>
#include <iostream>


class Solution {
public:

    std::vector<int> getPrefixSumArray(std::vector<int>& nums) {

        int n = nums.size();
        std::vector<int> prefixSum(n);

        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++) {

            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        return prefixSum;


    } 



    int subarraySum(std::vector<int>& nums, int k) {
        
        // Stores how many times each prefix sum has appeared
        std::unordered_map<int, int> prefix_count;

        // Before reading any element, prefix sum is 0
        // This helps count subarrays that start from index 0
        prefix_count[0] = 1;

        // Running prefix sum from index 0 to current index
        // int prefix_sum = 0;
        std::vector<int> prefixSum = getPrefixSumArray(nums);


        // Total number of subarrays whose sum equals k
        int count = 0;

        // Traverse each value in prefixSum
        for (int currentPrefix : prefixSum) {

            // We want:
            // currentPrefix - previousPrefix = k
            //
            // So:
            // previousPrefix = currentPrefix - k
            int needed = currentPrefix - k;

            // If this needed prefix sum appeared before,
            // then each occurrence creates one valid subarray
            if (prefix_count.find(needed) != prefix_count.end()) {
                count += prefix_count[needed];
            }

            // Store current prefix sum for future subarrays
            prefix_count[currentPrefix]++;
        }

        return count;
    }
};


int main () {

    // Create Solution object
    Solution test;

    
    // Size of the array
    int array_size;
    
    // Input size of the array
    do {
        std::cin >> array_size;
    } while (array_size < 1 || array_size > 20000);

    // Declare the array - vector
    std::vector<int> nums(array_size);


    // Input array
    for (int i = 0; i < array_size; i++) { 
        do {
            std::cin >> nums[i];
        } while (nums[i] < - 1000 || nums[i] > 1000);
    }

    // Target sum
    int k;

    // Input target sum
    do {
        std::cin >> k;
    } while (k < -10000000 || k > 10000000);




    // Call subarraySum() and store the result
    int num_of_subarray = test.subarraySum(nums, k);
    
    // Print the total number of subarrays whose sum is k
    printf("%d\n", num_of_subarray);

    // End program successfully
    return 0;
}