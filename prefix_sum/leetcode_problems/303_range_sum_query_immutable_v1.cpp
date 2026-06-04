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
    
        // 1st Improve
        if (left < 0 || left > right || right >= nums.size())
            throw std::out_of_range("Invalid range index");


        for(int i = left; i <= right; i++) {

            sum = sum + this->nums[i];

        }
        return sum;
    }
};




int main (void) {

    // 2nd Improve
    int sizeOfVec;
    
    printf("Size of Vector:\n");
    std::cin >> sizeOfVec;
    
    // Vector declaration
    std::vector<int> nums(sizeOfVec);

    // Input vector
    printf("Input the vector elements sequencially..\n");
    for (int i = 0; i < sizeOfVec; i++) 
        std::cin >> nums[i];

    // Object instantiate
    NumArray numArray(nums);

    // 3rd Improve
    int numOfRanges;
    int left, right;

    // Take number of range input
    std::cin >> numOfRanges;

    // Take range inputs
    for (int i = 0; i < numOfRanges; i++){

        std::cin >> left; 
        std::cin >> right;

        try{
            printf("%d\n", numArray.sumRange(left, right));        
        }

        catch (const std::out_of_range& e) {
            printf ("%s\n", e.what());
        }
    }

    return 0;
}