#include "max_avg_subarray_I.h"

#include<stdio.h>
#include <cassert>

void testLeetCodeExample() {

    int nums1 [] = {1,12,-5,-6,50,3};
    int numSize1 = 6;
    int k1 = 4;


    int nums2 [] = {5};
    int numSize2 = 1;
    int k2 = 1;

    assert(findMaxAverage(nums1, numSize1, k1) == 12.75000);
    assert(findMaxAverage(nums2, numSize2, k2) == 5.0000);

}

void testSingleElement() {

    int nums [] = {-1};
    int numSize = 1;
    int k = 1;

    assert(findMaxAverage(nums, numSize, k) == -1.0000);

}

void testAllPositiveNumbersOfDiffLength() {
    
    int nums1 [] = {4, 2, 1, 3};
    int numSize1 = 4;
    int k1 = 4;

    int nums2 [] = {3, 3, 3, 3, 3};
    int numSize2 = 5;
    int k2 = 3;

    int nums3 [] = {1, 2, 3, 100};
    int numSize3 = 4;
    int k3 = 2;

    assert(findMaxAverage(nums1, numSize1, k1) == 2.50000);
    assert(findMaxAverage(nums2, numSize2, k2) == 3.00000);
    assert(findMaxAverage(nums3, numSize3, k3) == 51.50000);

}

void testAllNegativeNumbers() {

    int nums1 [] = {-1, -12, -5, -6, -50, -3};
    int numSize1 = 6;
    int k1 = 2;

    assert(findMaxAverage(nums1, numSize1, k1) == -5.50000);
    
}



int main() {
    testLeetCodeExample();
    testSingleElement();
    testAllPositiveNumbersOfDiffLength();
    testAllNegativeNumbers();


    printf("All tests passed successfully.\n");

    return 0;
}