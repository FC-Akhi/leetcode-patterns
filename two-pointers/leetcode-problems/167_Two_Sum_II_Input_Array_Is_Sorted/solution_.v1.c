/* 
* Title: solution_v1
*
* Description:

*
* Approach (v1 solution):

*
* Improvement:

*
* Author: F.C.Fahi 
* Date: 16 August 2026 
*/




#include <stdio.h>
#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {

    int *ans = (int*)(malloc(*returnSize * sizeof(int)));

    int start = 0;
    int end = numbersSize - 1;
    while (start < end) {

        if (numbers[start] + numbers[end] == target) {
            
            ans[0] = start + 1;
            ans[1] = end + 1;
            return ans;
        }
        
        else if ((numbers[start] + numbers[end]) < target) {

            start++;
        }

        else if ((numbers[start] + numbers[end]) > target) {

            end--;
        }


    }

    return ans;


}





int main() {


    // Input the numbers array
    int numbers[] = {-1,0};

    int lengthOfNumbers =  sizeof(numbers) / sizeof(numbers[0]);

    int target = -1;

    int returnSize = 2;

    int *ans = twoSum(numbers, lengthOfNumbers, target, &returnSize);

  

    printf("[%d, %d]", ans[0], ans[1]);




    return 0;
}