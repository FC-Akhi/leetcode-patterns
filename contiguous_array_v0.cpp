#include<stdio.h>
#include<vector>
#include <map>

// Leetcode part starts here
/* 
* Class: Solution 
* Description: 
*   Solves the Contiguous Array problem.
*   Finds the maximum length of a contiguous subarray that contains
*   an equal number of 0s and 1s.
*
* Input: 
*   nums - A vector of integers containing only 0s and 1s.
*
* Output: 
*   An integer representing the maximum length of a contiguous subarray
*   with an equal number of 0s and 1s.
*
* Approach: 
*   1. Convert the binary array into a balance array:
*      - 0 becomes -1
*      - 1 becomes +1
*
*   2. Build a prefix sum array from the balance array.
*
*   3. Store all indices for each prefix sum value using a map.
*
*   4. For each prefix sum value, take the first and last index where it appears.
*      The difference between them gives the longest subarray length
*      for that prefix sum, where the subarray has equal number of 0s and 1s.
*
*   5. Return the maximum length found.
*
*/
class Solution {
public:

    // Solution(){};

    int findMaxLength(std::vector<int>& nums) {
        
        // Get the size of the input array
        int n = nums.size();

        // balance_array will store converted values:
        // 0 becomes -1
        // 1 becomes +1
        std::vector<int> balance_array(n);
        
        // Convert original nums array into balance_array
        for (int i = 0; i < n; i++) {

            if (nums[i] == 0)
                balance_array[i] = -1;

            else
                balance_array[i] = 1;

        }



        // prefix_sum will store running sums
        // Size is n + 1 because prefix_sum[0] = 0
        std::vector<int> prefix_sum(n+1);
        
        // Before taking any element, prefix_sum[0] is 0
        prefix_sum[0] = 0;

        // Build prefix sum array
        // prefix_sum[i + 1] = sum of balance_array[0] to balance_array[i]
        for(int i = 0; i < n; i++) {

            prefix_sum[i+1] = balance_array[i] + prefix_sum[i];

        }


        // Map each prefix sum value to all indices where it appears
        //
        // key   = prefix sum value
        // value = list of indices where this prefix sum appears
        std::map<int, std::vector<int>> map_value_indices;

        for(int i = 0; i < n+1; i++) {

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
// Leetcode part ends here



// For my own test in local machine
/* 
* Function: main 
* Description: 
* This function is used only for local testing. 
* LeetCode does not require the main function. 
* 
* Input: 
*   A vector is manually created: 
*   {0, 1, 1, 1, 1, 1, 0, 0, 0}
* 
* Process: 
*   1. Create a Solution object. 
*   2. Call findMaxLength() with input vector. 
*   3. Print the returned max_length. 
*/
// int main() {

//     std::vector<int> nums = {0, 1, 1, 1, 1, 1, 0, 0, 0};

//     Solution test;

//     int max_length = test.findMaxLength(nums);

//     printf("%d\n", max_length);
// }
