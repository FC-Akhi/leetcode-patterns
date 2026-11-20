/* 
* Title: find_pivot_index_v0
*
* Description: 
* Given an array of integers nums, calculate the pivot index of this array.

* The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly * to the index's right.

* If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right * edge of the array.

* Return the leftmost pivot index. If no such index exists, return -1.
*
* Approach: Optimized: implementing pattern technique
*
* Author: F.C.Fahi 
* Date: 20 Nov 2026 
*/

#include <stdio.h>



// Function for generating prefix sum
void prefix_sum(int *p_sum, const int *nums, int size_of_nums) {

    // first index value as 0 for future convenince of calculation
    p_sum[0] = 0;

    // insert first element of nums in p_sum
    p_sum[1] = nums[0];

    // Walk through the array num and generate prefix sum
    // store prefix sum in p_sum
    for (int i = 1; i < size_of_nums; i++) {

        p_sum[i+1] = p_sum[i] + nums[i];

    }

}


// Function for finding pivot index from pre calculated prefix sum array p_sum
int find_pivot_index (const int *p_sum, int size_of_p_sum) {


    // Variable initialization
    int left_sum = 0;
    int right_sum = 0;
    int pivot_index = 0;



    // Walk through each element of p_sum and check the condition for having pivot index
    for (int i = 1; i < size_of_p_sum; i++) {

        // Current index as pivot index
        pivot_index = i;

        // calculating sum of right part of the current pivot index
        right_sum = p_sum[size_of_p_sum - 1] - p_sum[pivot_index];
        left_sum = p_sum[pivot_index - 1];

        // // calculating sum of left part of the current pivot index
        // if (pivot_index != 0) 
        //     left_sum = p_sum[pivot_index - 1];


        // Return pivot index if left and right sum are equal
        if (left_sum == right_sum) {
            return (pivot_index - 1);
        }


    }

    // Return -1 if no pivot index found
    return -1;


}






int main (void) {


    // Array nums input

    // Test cases examples from leetcode
    // int nums[6] = {1, 7, 3, 6, 5, 6};
    // int nums[3] = {2, -1, 1};
    // int nums[3] = {1, 2, 3};

    // Extra test case
    // int nums[3] = {1, 1, 1};

    // Edge cases
    // int nums[1] = {5};
    // int nums[1] = {0};
    // int nums[2] = {1, 0};
    // int nums[2] = {0, 1};
    // int nums[2] = {1, 2};
    // int nums[3] = {1, -1, 2};
    // int nums[3] = {0, 0, 0};
    // int nums[4] = {1, -1, 0, 0};
    // int nums[2] = {-1, 1};
    int nums[6] = {-1, -1, -1, -1, -1, 0};


    // Calculating size of nums
    int size_of_nums = sizeof(nums) / sizeof(nums[0]);


    // Size of p_sum
    int size_of_p_sum = size_of_nums + 1;


    // Taking same size of prefix sum array p_sum
    int p_sum[size_of_p_sum];


    // Generate prefix sum
    prefix_sum(p_sum, nums, size_of_nums);


    // Print the prefix sum for checking
    // for (int i = 0; i < size_of_nums + 1; i++)
    // {
    //     printf("%d ", p_sum[i]);
    // }
    



    // Find pivot index
    int pivot_index = find_pivot_index(p_sum, size_of_p_sum);


    // Print pivot index
    printf("%d\n", pivot_index);

    
    return 0;



}
