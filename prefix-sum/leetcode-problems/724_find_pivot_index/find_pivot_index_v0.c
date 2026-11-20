/* 
* Title: find_pivot_index_v0
*
* Description: 
* Given an array of integers nums, calculate the pivot index of this array.

* The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly * to the index's right.

* If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right * edge of the array.

* Return the leftmost pivot index. If no such index exists, return -1.
*
* Approach: Bruteforce - Naive
*
* Author: F.C.Fahi 
* Date: 19 Nov 2026 
*/



#include <stdio.h>
#include <stdbool.h>

int main (void) {


    // Array input nums
    int nums[6] = {1, 1, 1};


    // Variable decalrations
    int left_sum = 0;
    int right_sum = 0;
    int pivot_index = 0;
    bool found = 0;
    


    // Find pivot index
    for (int i = 0; i < 3; i++) {

        pivot_index = i;


        // Calculate right sum
        for (int j = i + 1; j < 3; j++) {

            right_sum = right_sum + nums[j];

        }

        // Check the condition, if left_sum == right_sum
        if (left_sum == right_sum) {

            printf("%d\n", pivot_index);

            found = 1;

            break;

        }

        // Calculate left sum
        left_sum = left_sum + nums[i];


        // Initialize right sum back to 0
        right_sum = 0;

    }

    // If the pivot index not found return -1
    if (!found)
        printf("-1");



    return 0;

}
