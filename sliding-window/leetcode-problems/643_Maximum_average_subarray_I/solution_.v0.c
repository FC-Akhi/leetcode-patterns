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
* 1. Will be use bruteforce approach using nested for loop
* 2. Hard coded inputs
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

    for (int i = 0; i <= actual_len; i++) {

        for (int j = i; j < i + k; j++) {

            sum = sum + nums[j];

        }

        min_avg = (double)sum / k;

        printf("%f\n", min_avg);

        if (min_avg > max_avg) 
            max_avg = min_avg;

        sum = 0;
    }

    return max_avg;
        


}


int main (void) {

    int nums[] = {10000};

    int k = 1;

    int numsSize = (sizeof(nums) / sizeof nums[0]);

    double max_avg_subarray = findMaxAverage(nums, numsSize, k);

    printf("%f", max_avg_subarray);

}

