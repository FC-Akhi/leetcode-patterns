#include<stdio.h>
#include<vector>
#include <map>

// Leetcode part starts here
/* 
* Class: Solution
*
* Description:
*   Solves LeetCode 525: Contiguous Array.
*   The goal is to find the maximum length of a contiguous subarray
*   that contains an equal number of 0s and 1s.
*
* Approach:
*   This is a brute-force style solution.
*
*   1. Convert the original binary array into a balance array:
*      - 0 becomes -1
*      - 1 becomes +1
*
*   2. For every possible starting index, expand the subarray one element
*      at a time.
*
*   3. Keep a running sum of the balance values for the current subarray.
*
*   4. If the running sum becomes 0, it means the current subarray has
*      equal number of 0s and 1s.
*
*   5. Track and update the maximum length found.
*
* Input:
*   nums - A vector containing only 0s and 1s.
*
* Output:
*   Returns the maximum length of a contiguous subarray with equal
*   number of 0s and 1s.
*
* Time Complexity:
*   O(n^2)
*   Because the code checks subarrays using two nested loops.
*
* Space Complexity:
*   O(n)
*   Because a balance_array is created, and an additional vector is used
*   to track the current subarray values.
*/
class Solution {
public:

    // Solution(){};

    int findMaxLength(std::vector<int>& nums) {
        
        // Get the sise of input nums
        int n = nums.size();

        // Declare empty vector for balance array
        std::vector<int> balance_array(n);

        // Generate balance array
        for(int i = 0; i < n; i++) {
            if (nums[i] == 0) 
                balance_array[i] = -1;
            else
                balance_array[i] = 1;
        }

        // Declare helper variables and vector
        int sum = 0;
        int length = 0;
        int max_length = 0;
        std::vector<int> numbers;


        // Iterating over each numbers to find the maximum length of 0s and 1s
        for (int i = 0; i < n - 1; i++) {

            sum = balance_array[i];
            numbers.push_back(balance_array[i]);

            for (int j = i+1; j < n; j++){

                sum = sum + balance_array[j];
                numbers.push_back(balance_array[j]);

                if(sum == 0) {
                    length = numbers.size();
                    if (max_length < length)
                        max_length = length;
                }
            }
            numbers.clear();
        }

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
*   A vector is manually created
* 
* Process: 
*   1. Create a Solution object. 
*   2. Call findMaxLength() with input vector. 
*   3. Print the returned max_length. 
*/
int main() {

    std::vector<int> nums = {0, 0, 1, 0, 1, 1};
    int check = 1;

    // Check is all input values in the vector are 0s or 1s
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 1 && nums[i] < 0) {
            printf("array numbers should be 0s and 1s\n");
            check = 0;
        }
    }


    if (check) {
        Solution test;

        int max_length = test.findMaxLength(nums);

        printf("%d\n", max_length);
    }
}
