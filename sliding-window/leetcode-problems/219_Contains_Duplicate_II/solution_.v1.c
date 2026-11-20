/* 
* Title: solution_v0
*
* Description:
* Given an integer array nums and an integer k, return true if there are two 
* distinct indices i and j in the array such that nums[i] == nums[j] and 
* abs(i - j) <= k.
*
*
* Approach (v0 solution):
* 1. Will be use bruteforce approach using nested for loop
* 2. Taken user inputs
*
* Author: F.C.Fahi 
* Date: 21 Aug 2026 
*/


// For bool, true, and false
#include <stdbool.h>

// For printf function
#include<stdio.h>

// For abs function
#include<stdlib.h>



bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    

    for (int i = 0; i < numsSize - 1; i++) {

        for (int j = i + 1; j < numsSize; j++) {

            if (nums[i] == nums [j] && abs(i - j) <= k) 

                return true;

        }
    }

    return false;

}


int main (void) {


    // Take the array size as input
    int arraySize;

    printf("Enter array size\n");
    scanf("%d", &arraySize);

    int nums[arraySize];

    // Take array elements as input
    for (int i = 0; i < arraySize; i++)
        scanf("%d ", &nums[i]);

    
    // Take an integer input
    int k;

    scanf("%d", &k);

    bool status = containsNearbyDuplicate(nums, arraySize, k);

    if (status)        
        printf("true");

    else
        printf("false");


    return 0;

}

