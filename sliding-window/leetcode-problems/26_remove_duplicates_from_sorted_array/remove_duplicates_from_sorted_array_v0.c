/* 
* Title: remove_duplicates_from_sorted_array_v0
*
* Description: 
* Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

* Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

* The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.
*
* Approach: Optimized - Using two pointers
*
* Author: F.C.Fahi 
* Date: 23 Nov 2026 
*/



#include <stdio.h>

int removeDuplicates(int *nums, int numSize) {

    int j = 0;

    // loop through nums array and check unique elements in the array
    // store all unique elements in the nums at from the starting of the nums
    for (int i = 1; i < numSize; i++) {

        if (nums[j] != nums[i]) {

            j++; 
            nums[j] = nums[i]; 

        }
    }


    // for (int i = 0; i < numSize; i++)
    // {
    //     printf("%d ", nums[i]);
    // }
    

    // total number of unique elements
    int k = j + 1;

    // return total number of unique element
    return k;


}





int main (void) {


    // declare and initialize nums array
    int nums[10] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    // declare and initialize size of nums array
    int sizeOfNums = sizeof(nums) / sizeof(nums[0]);

    // function call for calculating number of unique elements in the array
    // returns number of unique element in the array nums
    int k = removeDuplicates(nums, sizeOfNums);

    // print the output
    printf("%d\n", k);


    return 0;
}