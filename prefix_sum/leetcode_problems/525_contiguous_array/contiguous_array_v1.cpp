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
