/* 
* Title: Prefix Sum Pattern 
* Description: This program creates a prefix sum array from a given array. 
* It also calculates the sum of elements between a start index and an end index.
* This is the very initial implememntation which came to my mind.
* Code may be bruteforce in some part in some part optimized.
* Author: F.C.Fahi
* Date: 03 June 2026 
*/


// Includes the standard input-output library for printf and scanf
#include<stdio.h> 


/* 
* Function: get_prefix_sum_arr 
* Description: This function creates a prefix sum array from the input array. 
* Parameters: 
*   a - Pointer to the input array. 
*   prefix_sum - Pointer to the output prefix sum array. 
*   len_a - Length of the input array. 
* Return: 
*   This function does not return anything. 
*/
void get_prefix_sum_arr(int *a, int *prefix_sum, int len_a) {
    
    // Declares a variable to store the sum for each index
    int sum;

    // Loops through each index of the input array
    for(int i = 0; i < len_a; i++) {

        sum = 0; 

        // Checks if the current index is the first index
        if(i == 0) {
            
            // Stores the first element directly in the prefix sum array
            prefix_sum[i] = a[i];

        }
        
        // Runs this block for all indexes except the first index
        else {

            for (int j = i; j >= 0 ; j--) {

                sum = sum + a[j];
            }

            // Stores the calculated sum in the prefix sum array
            prefix_sum[i] = sum;

        }
    }
}

/* 
* Function: print_prefix_sum-array 
* Description: This function print already created prefix sum array. 
* Parameters: 
*   prefix_sum - Pointer to the prefix sum array. 
*   len - length of array 
* Return: 
*   void, only prints
*/
void print_prefix_sum_array(int *prefix_sum, int len) {

    for (int i = 0; i < len; i++) 
        // Prints each prefix sum value 
        printf("%d ", prefix_sum[i]); 

}





/* 
* Function: get_total_prefix_sum 
* Description: This function calculates the sum of elements from 
* start index to end index from already created prefix sum array. 
* Parameters: 
*   prefix_sum - Pointer to the prefix sum array. 
*   start - Starting index of the range. 
*   end - Ending index of the range. 
* Return: 
*   Returns the total sum from start index to end index. 
*/
int get_total_prefix_sum(int *prefix_sum, int start, int end) {

    // Declares a variable to store the range sum
    int total_prefix_sum = 0;

    // Checks if the range starts from index 0
    if(start == 0)
        // If start is 0, the answer is prefix_sum[end]
        total_prefix_sum = prefix_sum[end];
    
    // Runs this block when start is not 0
    else
        // Subtracts previous prefix sum to get range sum
        total_prefix_sum = prefix_sum[end] - prefix_sum[start - 1];


    return total_prefix_sum;
}



/* 
* Function: main 
* Description: This is the main function where program execution starts. 
*/
int main (void) {


    // Declares and initializes the input static array 
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    // Declares and initializes the prefix sum array with 0 
    int prefix_sum[10] = {0}; 
    // Calculates the number of elements in the input array 
    int len_a = sizeof(a) / sizeof(int); 
    
    // Calls the function to create the prefix sum array 
    get_prefix_sum_arr(a, prefix_sum, len_a); 
    
    // Print prefix sum array 
    print_prefix_sum_array(prefix_sum, len_a);
    
    

    // Declares variables to store start and end indexes 
    int start, end; 
    
    // Takes start and end index input from the user 
    scanf("%d %d", &start, &end); 
    
    // Calculates range sum using prefix sum array 
    int total_prefix_sum = get_total_prefix_sum(prefix_sum, start, end); 
    
    // Prints the calculated range sum 
    printf("%d", total_prefix_sum); 
    
    return 0; 
}