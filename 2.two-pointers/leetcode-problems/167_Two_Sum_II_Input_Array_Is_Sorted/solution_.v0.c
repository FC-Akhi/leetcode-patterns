/* 
* Title: solution_v0
*
* Description:

*
*
* Approach (v0 solution):

*
* Author: F.C.Fahi 
* Date: 26 June 2026 
*/


#include <stdio.h>
#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {

    int *ans = (int*)(malloc(*returnSize * sizeof(int)));


    for (int i = 0; i < numbersSize; i++) {

        for (int j = i + 1; j < numbersSize; j++) {

            if (numbers[i] + numbers[j] == target) {

                ans[0] = i+1;
                ans[1] = j+1;
                
                return ans;
            }
        }
    }

    return ans;


}

int main() {

    // Input the numbers array
    int numbers[] = {-1,0};

    int target = -1;

    int returnSize = 2;

    int *ans = twoSum(numbers, 2, target, &returnSize);

  

    printf("[%d, %d]", ans[0], ans[1]);

    return 0;
}