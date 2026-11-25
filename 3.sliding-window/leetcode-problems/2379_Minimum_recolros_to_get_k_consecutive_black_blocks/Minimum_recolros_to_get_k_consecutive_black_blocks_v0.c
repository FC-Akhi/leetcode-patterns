/* 
* Title: Minimum_recolros_to_get_k_consecutive_black_blocks_v0
*
* Description: 
You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.

You are also given an integer k, which is the desired number of consecutive black blocks.

In one operation, you can recolor a white block such that it becomes a black block.

Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.
*
* Approach: Bruteforce approach
*
* Author: F.C.Fahi 
* Date: 25 Nov 2026 
*/

#include <stdio.h>
#include <string.h>

int minimumRecolors(char* blocks, int k) {
    
    // blocks is a C string, which means it ends with '\0'. strlen counts the 
    // characters up to that terminator
    int sizeOfBlocks = strlen(blocks);


    // printf("%d\n", sizeOfBlocks);


    int count = 0;
    int min = k;
    

    for (int i = 0; i < sizeOfBlocks; i++)
    {
        /* code */
        for (int j = i; j < i + k && i + k <= sizeOfBlocks; j++)
        {
            /* code */
            if (blocks[j] == 'W')
                count++;
                
        }
        
        // printf("%d \n", count);

        if (min > count &&  i + k <= sizeOfBlocks) {
            min = count;
        }
        count = 0;

    }
    
    return min;

}



int main (void) {

    // input array
    char blocks[] = {"BWWWW"};

    
    // given input window size
    int k = 2;

    // printf("%d\n", sizeOfBlocks);

    // for (int i = 0; i < sizeOfBlocks; i++) {
    //     printf("%c ", blocks[i]);
    // }


    int minNumbersOfOps = minimumRecolors(blocks, k);

    printf("%d\n", minNumbersOfOps);




}