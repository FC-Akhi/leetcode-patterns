/* 
* Title: LeetCode 303 - Range Sum Query Immutable
*
* Description: 
* This program implements a simple version of the NumArray class for solving
* range sum queries. The program takes a vector size and vector elements from
* the user, then creates a NumArray object using that vector.
*
* After that, the program takes multiple range queries. For each query, it
* calculates the sum of elements from the left index to the right index,
* including both indices.
*
* The sumRange() method uses a brute-force approach by looping from left to
* right for every query. It also checks invalid ranges, such as negative left
* index, left greater than right, or right index outside the vector size.
* If the range is invalid, it throws an out_of_range exception, and the main
* function catches the exception and prints an error message.
*
* Approach:
* Brute-force range sum calculation
*
* Author: F.C.Fahi 
* Date: 04 June 2026 
*/
#include <iostream>
#include<stdio.h>
#include<vector>

// Part of Improvement - 1
#include <stdexcept>


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




int main (void) {

    
    int sizeOfVec;

    // Validate vector size based on constraint - 1st improvement
    do {    
        printf("Size of input array or vector in range 1 <= size <= 10^4:\n");
        std::cin >> sizeOfVec;
    } while (sizeOfVec < 1 || sizeOfVec > 10000);
    
    
    // Vector declaration
    std::vector<int> nums(sizeOfVec);

    
    // Input vector
    printf("Input the vector elements with enter..\n");
    for (int i = 0; i < sizeOfVec; i++) {
        
        // Validate each element based on constraint - 2nd improvement
        do {
            printf("Insert value:");
            std::cin >> nums[i];
        } while (nums[i] < -100000 || nums[i] > 100000);
    }


    // Object instantiate
    NumArray numArray(nums);

    
    int numOfRanges;
    int left, right;

    // Take number of range queries
    // Validate each element based on constraint - 2nd improvement
    do{
        printf("Take number of ranges:\n");
        std::cin >> numOfRanges;
    } while (numOfRanges < 0 || numOfRanges > 10000);
    
    
    // Take range inputs
    for (int i = 0; i < numOfRanges; i++){
        
        do {
            printf("Enter left and right of the range:\n");
            std::cin >> left; 
            std::cin >> right;
        } while(left < 0 || left > right || right >= nums.size());
        
        // Validate range inside sumRange() - 2nd improvement
        printf("%d\n", numArray.sumRange(left, right));        

    }

    return 0;
}