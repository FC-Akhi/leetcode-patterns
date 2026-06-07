/*
* Title: range_sum_query_immutable_v3
*
* Description:
* This program implements a local testing version of the Range Sum Query problem.
* It takes an input vector from the user, validates the vector size and element
* values based on the given constraints. It then creates a NumArray object.
*
* The program builds a prefix sum vector from the input vector. After that, it
* validates multiple ranges and answer range sum queries using the prefix sum 
* vector.
*
* In this version, the prefix sum vector is created using a brute-force approach.
* For each index, the code recalculates the sum from index 0 to the current index.
* However, after the prefix sum vector is created, each range sum query is answered
* in constant time using the prefix sum formula. 
*
* Main Improvements:
* 1. Validates input vector size, each vector element and range values. 
* And Takes input from the user for local testing (previous - v1)
* 2. Creates a prefix sum vector and Answers range sum queries in 
* O(1) time after prefix sum construction. (previous - v2)
*
* Approach:
* Prefix sum construction (bruteforce) + range sum query (constant time).
*
*
* Author: F.C.Fahi
* Date: 06 June 2026
*/


/*
* Title: range_sum_query_immutable_v3
*
* Description:
* This program implements a local testing version of the Range Sum Query problem.
* It takes an input vector from the user, validates the vector size and element
* values based on the given constraints, and then creates a NumArray object.
*
* The program builds a prefix sum vector from the input vector. After that, it
* validates multiple range inputs and answers range sum queries using the prefix
* sum vector.
*
* In this version, the prefix sum vector is created using an optimized approach.
* Instead of recalculating the sum from index 0 to the current index every time,
* it uses the previous prefix sum value to calculate the next prefix sum value.
*
* Formula:
* prefixSum[i] = prefixSum[i - 1] + nums[i]
*
* After the prefix sum vector is created, each range sum query is answered in
* constant time using the prefix sum formula.
*
* Main Improvements:
* 1. Validates input vector size, each vector element, and range values.
*    Also takes input from the user for local testing. (previous - v1)
*
* 2. Creates a prefix sum vector and answers range sum queries in O(1) time
*    after prefix sum construction. (previous - v2)
*
* 3. Optimizes prefix sum construction from O(n^2) to O(n) by reusing the
*    previous prefix sum value. (current - v3)
*
* Approach:
* Optimized prefix sum construction + constant-time range sum query.
*
* Author: F.C.Fahi
* Date: 06 June 2026
*/



#include <iostream>
#include<stdio.h>
#include<vector>


// 0: off debugging
// 1: on debugging
bool DEBUG =  1; 

class NumArray {

public:

    // Class variable, vector int type 
    std::vector<int> nums;
    
    // Constructor
    NumArray(
        std::vector<int>& nums
    ) {

        // class vector which is the copy of input vector
        this->nums = nums;
    }


    /* 
    * Method: getPrefixSum 
    * Description: 
    * This method creates a prefix sum vector from the given input vector. 
    * For each index i, it calculates the sum of all elements 
    * from index 0 to index i. 
    * 
    * This is a brute-force prefix sum construction because for every index, 
    * it loops backward and recalculates the sum from the current index to index 0. 
    * 
    * Parameters: 
    *   nums - Reference to the input vector. 
    *   sizeOfVec - Size of the input vector. 
    * Output: 
    *    Returns a prefix sum vector. 
    */
    std::vector<int> getPrefixSum(
        const std::vector<int>& nums, 
        int sizeOfVec) {

        // Vector declaration
        std::vector<int> prefixSum(sizeOfVec);

        int sum = 0;
        
        // Optimizes prefix sum construction from O(n^2) to O(n) - 3rd stage improvement
        prefixSum[0] = nums[0];

        for(int i = 1; i < sizeOfVec; i++) {
                
            prefixSum[i] = prefixSum[i-1] + nums[i];
        
        }

        // pointer to the vector
        return prefixSum;
    }


    // Method
    int sumRange(
        const std::vector<int>& prefixSum,
        int left, 
        int right) {
        

        // Using Prefix Sum and calulating range 
        // sum query in constant time - 2nd stage improvement 
        if(left == 0) {
            return prefixSum[right];
        }

        return (prefixSum[right] - prefixSum[left - 1]);
    }


};




int main (void) {

    
    int sizeOfVec;

    // Validate vector size based on constraint - 1st stage improvement
    do {    
        printf("Size of input array or vector in range 1 <= size <= 10^4:\n");
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
            std::cin >> nums[i];
        } while (nums[i] < -100000 || nums[i] > 100000);
    }


    // Object instantiate
    NumArray numArray(nums);

    
    // Prefix sum operation - 2nd stage improvement
    std::vector<int> prefixSum = numArray.getPrefixSum(nums, sizeOfVec);
    
    // Debugging
    if(DEBUG) {
        printf("Prefix Sum vector:\n");
        for(int i = 0; i < sizeOfVec; i++)
            printf("%d ", prefixSum[i]);
    }


    int numOfRanges;
    int left, right;

    // Take number of range queries
    // Validate each element based on constraint - 1st stage improvement
    do{
        printf("\nHow many range?\n");
        std::cin >> numOfRanges;
    } while (numOfRanges < 0 || numOfRanges > 10000);
    
    
    // Take range inputs
    for (int i = 0; i < numOfRanges; i++){
        
        do {
            printf("Enter left and right of the range:\n");
            std::cin >> left; 
            std::cin >> right;
        } while(left < 0 || left > right || right >= nums.size());
        
        // Constant time operation inside sumRange() - 2nd stage improvement
        printf("%d\n", numArray.sumRange(prefixSum, left, right));        

    }

    return 0;
}