/* 
* Title: subarray_sum_equals_k_v0
*
* Description: 
* Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
* A subarray is a contiguous non-empty sequence of elements within an array.
*
* Approach: Bruteforce
*
* Author: F.C.Fahi 
* Date: 09 July 2026 
*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>

class Solution {
public:
    // Function to count the total number of contiguous subarrays
    // whose sum is equal to k
    int subarraySum(std::vector<int>& nums, int k) {
        
        // Store the size of the input vector
        int n = nums.size();

        // l is used as a unique key for each generated subarray
        int l = 0;
        
        // This map stores all generated subarrays
        // key   = unique subarray number
        // value = vector containing the elements of that subarray
        //
        // Note: This is std::map, not a key_value map.
        std::map<int, std::vector<int>> key_value_map;

        // Outer loop selects the starting index of a subarray
        for (int i = 0; i < n; i++) {
            // Middle loop selects the ending index of a subarray
            for (int j = i; j < n; j++) {

                // Inner loop goes from start index i to end index j
                // and stores all elements of the current subarray
                for (int k = i; k <= j; k++) {

                    // Insert nums[k] into the vector stored at key l
                    // This means key_value_map[l] stores one complete subarray
                    key_value_map[l].push_back(nums[k]);

                }
                // Move to the next key for the next subarray
                l+=1;
           } 
        }


        // sum stores the sum of one subarray at a time
        int sum = 0;

        // count stores how many subarrays have sum equal to k
        int count = 0;


        // Iterate through every key-value pair in the map
        for (const auto& pair :key_value_map) {

            // pair.first  = key/subarray number
            // pair.second = vector containing subarray elements

            // Add all values of the current subarray
            for (int value : pair.second)
                sum = sum + value;

            // If the current subarray sum equals target k,
            // increase the count
            if (sum == k)
                count += 1;

            // Reset sum before checking the next subarray
            sum = 0;
        }
        
        
        // Return total number of subarrays whose sum equals k
        return count;
    }
};


int main () {

    // Create Solution object
    Solution test;

    // Input array
    std::vector<int> nums = {1, 2, 3};

    // Target sum
    int k = 3;

    // Call subarraySum() and store the result
    int num_of_subarray = test.subarraySum(nums, k);
    
    // Print the total number of subarrays whose sum is k
    printf("%d\n", num_of_subarray);

    // End program successfully
    return 0;
}