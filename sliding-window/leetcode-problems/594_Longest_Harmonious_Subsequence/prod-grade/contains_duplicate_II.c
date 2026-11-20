
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