// For bool, true, and false
#include <stdbool.h>

// For printf function
#include<stdio.h>

// For abs function
#include<stdlib.h>



typedef struct {
    int index;
    int value;
} NUM;

int compare(const void* a, const void* b) {

    printf("%d %d\n", (*(NUM*)a).value, (*(NUM*)a).index);
    printf("%d %d\n", (*(NUM*)b).value, (*(NUM*)b).index);

    return ((*(NUM*)a).value - (*(NUM*)b).value);
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {

    NUM* num = malloc(sizeof(NUM)*numsSize);

    bool ans = false;

    for ( int i = 0; i < numsSize; i++ ) {
        num[i].value = nums[i];
        num[i].index = i;
    }

    qsort(num, numsSize, sizeof(NUM), compare);
    for ( int i = 1; i < numsSize; i++ ) {
        if ( num[i].value == num[i-1].value && (num[i].index - num[i-1].index) <= k ) {

            ans = true;
            break;

        }
    }

    free(num);
    return false;
}





int main (void) {


    int nums[] = {1,2,3,1,2,3};

    int k = 2;

    int numsSize = sizeof(nums) / sizeof(nums[0]);

    bool status;

    status = containsNearbyDuplicate(nums, numsSize, k);

    if (status) 
        printf("true");

    else
        printf("false");

    return 0;
}
