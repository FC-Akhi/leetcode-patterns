/* 
* Title: contiguous_array_v1
*
* Description: 
* This program implements LeetCode 525: Contiguous Array.
* It takes an input binary vector containing only 0s and 1s.
*
* The goal is to find the maximum length of a contiguous subarray
* that contains an equal number of 0s and 1s.
*
* The program first converts the binary array into a balance array:
* 0 becomes -1, and 1 becomes +1.
*
* After that, it checks every possible contiguous subarray by expanding
* from each starting index. For each subarray, it calculates a running sum
* of the balance values.
*
* If the running sum becomes 0, it means the current subarray contains
* an equal number of 0s and 1s.
*
* The program tracks and updates the maximum valid subarray length found.
*
* Main Improvements:
* 1. Validates input vector size, each vector element 
* And Takes input from the user for local testing.
* 2. Improve reduce extra O(n) of space.
*
* Approach:
* Optimized Bruteforce
*
* Author: F.C.Fahi 
* Date: 08 July 2026 
*/



#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>

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
        }

        return balance_array;

    }


    // Get the maximum length of contiguous subarray of 0s and 1s
    int findMaxLength(std::vector<int>& nums) {
        
        // Get the sise of input nums
        int n = nums.size();

        // Declare empty vector for balance array
        std::vector<int> balance_array(n);

        // Get balance array
        balance_array = getBalanceArray(nums, n);

        // Declare helper variables and vector
        int sum = 0;
        int length = 0;
        int max_length = 0;
        


        // Iterating over each numbers to find the maximum length of 0s and 1s
        for (int i = 0; i < n - 1; i++) {

            sum = balance_array[i];
            

            for (int j = i+1; j < n; j++){

                sum = sum + balance_array[j];
            

                if(sum == 0) {
                    length = (j - i) + 1;
                    if (max_length < length)
                        max_length = length;
                }
            }
        }

        return max_length;



    }
};



// For my own test in local machine
/* 
* Function: main 
* Description: 
* This function is used only for local testing. 
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

    int sizeOfNums;
    
    do {
        std::cin >> sizeOfNums;
    } while (sizeOfNums < 1 || sizeOfNums > 100000);


    std::vector<int> nums(sizeOfNums);
   
    for (int i = 0; i < sizeOfNums; i++) {

        do {
            std::cin >> nums[i];
        } while (nums[i] < 0 || nums[i] > 1);
    }
    

    Solution test;

    int max_length = test.findMaxLength(nums);
    
    printf("%d\n", max_length);
    
    return 0;
}
