/* 
* Title: subarray_sum_equals_k_v1
*
* Description: 
* Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
* A subarray is a contiguous non-empty sequence of elements within an array.
*
* Approach: Bruteforce Optimized
*
* Author: F.C.Fahi 
* Date: 10 July 2026 
*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<unordered_map>

class Solution {
public:


    int listSubArrays(std::vector<int>& nums, int n, int input_k) {
        

        int sum = 0; 
        int count = 0;

        // Outer loop selects the starting index of a subarray
        for (int i = 0; i < n; i++) {
            // Middle loop selects the ending index of a subarray
            for (int j = i; j < n; j++) {

                // Inner loop goes from start index i to end index j
                // and stores all elements of the current subarray
                for (int k = i; k <= j; k++) {
                    // Record the total sum of the subarray element
                    sum = sum + nums[k];
                }
                
                // Compare the sum of the subarray with given integer
                // If the total sum is equal to given integer, then count will increase
                if (sum == input_k) {
                    count++;
                    
                }
                sum = 0;
           } 
        }

        return count;
        
    }

    // Function to count the total number of contiguous subarrays
    // whose sum is equal to k
    int subarraySum(std::vector<int>& nums, int k) {
        
        // Store the size of the input vector
        int n = nums.size();
        int count = listSubArrays(nums, n, k);
        
        // Return total number of subarrays whose sum equals k
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