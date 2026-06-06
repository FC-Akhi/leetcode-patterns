/* 
* Title: range_sum_query_immutable_v1
*
* Description: 
* This program implements a local testing version of the Range Sum Query problem.
* It takes an input vector from the user, validates the vector size and element
* values based on the given constraints, and then creates a NumArray object
*
* After that, the program takes multiple range queries. It also validates the 
* range values. 
* For each query, it calculates the sum of elements from the left index 
* to the right index, including both indices.
*
* The sumRange() method uses a brute-force approach by looping from left to
* right for every query. 
*
* Main Improvements:
* 1. Validates input vector size, each vector element and range values. 
* And Takes input from the user for local testing. (current)
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

    // Validate vector size based on constraint - 1st stage improvement
    do {    
        printf("Size of input array or vector in range 1 <= size <= 10^4:\n");
        // Take user input - 1st stage improvement
        std::cin >> sizeOfVec;
    } while (sizeOfVec < 1 || sizeOfVec > 10000);
    
    
    // Vector declaration
    std::vector<int> nums(sizeOfVec);

    
    // Input vector
    printf("Input the vector elements with enter..\n");
    for (int i = 0; i < sizeOfVec; i++) {
        
        // Validate each element based on constraint - 1st stage improvement
        do {
            printf("Insert value:");
            // Take user input - 1st stage improvement
            std::cin >> nums[i];
        } while (nums[i] < -100000 || nums[i] > 100000);
    }


    // Object instantiate
    NumArray numArray(nums);

    
    int numOfRanges;
    int left, right;

    // Take number of range queries
    // Validate each element based on constraint - 1st stage improvement
    do{
        printf("Take number of ranges:\n");
        // Take user input - 1st stage improvement
        std::cin >> numOfRanges;
    } while (numOfRanges < 0 || numOfRanges > 10000);
    
    
    // Take range inputs
    for (int i = 0; i < numOfRanges; i++){
        
        do {
            printf("Enter left and right of the range:\n");
            std::cin >> left; 
            std::cin >> right;
        } while(left < 0 || left > right || right >= nums.size());
        
        // Validate range inside sumRange() - 1st stage improvement
        printf("%d\n", numArray.sumRange(left, right));        

    }

    return 0;
}