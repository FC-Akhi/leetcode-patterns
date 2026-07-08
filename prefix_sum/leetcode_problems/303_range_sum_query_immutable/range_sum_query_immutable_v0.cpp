/* 
* Title: range_sum_query_immutable_v1
*
* Description: 
* This program implements the Range Sum Query problem.
* It takes an input vector, and then creates a NumArray object
*
* After that, the program takes a range query. It also validates the 
* range values. 
* For each query, it calculates the sum of elements from the left index 
* to the right index, including both indices.
*
* The sumRange() method uses a brute-force approach by looping from left to
* right for every query. 
*
* Approach:
* Brute-force range sum calculation. This is the very initial code structure.
*
* Author: F.C.Fahi 
* Date: 04 June 2026 
*/
#include <iostream>
#include<stdio.h>
#include<vector>


class NumArray {

public:

    // Class variable, vector int type 
    std::vector<int> nums;
    
    // Constructor
    NumArray(std::vector<int>& nums) {


        this->nums = nums;
    }

    // Method
    int sumRange(int left, int right) {
        
        int sum = 0;

        for(int i = left; i <= right; i++) {

            sum = sum + this->nums[i];

        }
        return sum;
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
*   1. Create a NumArray object. 
*   2. Take left and right of the range.
*   2. Call sumRange() with input ranges. 
*   3. Print the returned sum of the numbers in range. 
*/
int main (void) {


    // Vector declaration & initialization
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    
    // Object instantiate
    NumArray numArray(nums);

    // Variable decalaration
    int left, right;

    // Range input
    left = 2;
    right = 5;

    printf("%d\n", numArray.sumRange(left, right));        


    return 0;
}