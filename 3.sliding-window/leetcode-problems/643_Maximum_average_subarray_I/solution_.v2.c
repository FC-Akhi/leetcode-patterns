/* 
* Title: solution_v0
*
* Description:
* You are given an integer array nums consisting of n elements, and an integer k.

* Find a contiguous subarray whose length is equal to k that has the maximum 
* average value and return this value. 
* Any answer with a calculation error less than 10-5 will be accepted.
*
*
* Approach (v0 solution):
* 1. Will be using sliding window technique
*
* Author: F.C.Fahi 
* Date: 19 Aug 2026 
*/


#include<stdio.h>

double findMaxAverage (int *nums, int numsSize, int k) {


    int actual_len = numsSize - k;

    int sum = 0;

    double min_avg = 0.00000;
    double max_avg = -10001.0; 

    for (int i = 0; i < k; i++)
        sum = sum + nums[i]  ;

    min_avg = (double)sum / k;

    if (min_avg > max_avg) 
        max_avg = min_avg;


    for (int i = 1; i <= actual_len; i++) {

        sum = sum - nums[i-1] + nums[i + k - 1];        

        min_avg = (double)sum / k;

        // printf("%f\n", min_avg);

        if (min_avg > max_avg) 
            max_avg = min_avg;

        // sum = 0;
    }

    return max_avg;
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

    double max_avg_subarray = findMaxAverage(nums, arraySize, k);

    printf("%f", max_avg_subarray);

}

