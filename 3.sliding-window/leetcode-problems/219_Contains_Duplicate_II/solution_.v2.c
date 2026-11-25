/* 
* Title: solution_v0
*
* Description:
* Given an integer array nums and an integer k, return true if there are two 
* distinct indices i and j in the array such that nums[i] == nums[j] and 
* abs(i - j) <= k.
*
*
* Approach (v0 solution):
* 1. Implementing sliding window technique
*
* Author: F.C.Fahi 
* Date: 22 Aug 2026 
*/


// For bool, true, and false
#include <stdbool.h>

// For printf function
#include<stdio.h>

// For abs function
#include<stdlib.h>



#define TABLE_SIZE 100000


typedef struct IndexNode {

    int index;
    struct IndexNode* next;

} IndexNode;


typedef struct HashNode {

    int key;    // nums[i]
    IndexNode* indices;  // list of all indices where key appears

    struct HashNode* next;

} HashNode;


int hashFunc(int key) {

    long long x = key;

    if (x < 0)
        x = -x;

    return x % TABLE_SIZE;


}

int addIndexTailAndGetPrevious(IndexNode** head, int index) {
    IndexNode* newNode = malloc(sizeof(IndexNode));
    newNode->index = index;
    newNode->next = NULL;

    // If this key has no previous index
    if (*head == NULL) {
        *head = newNode;
        return -1;   // no previous index exists
    }

    IndexNode* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    int previousLastIndex = current->index;

    current->next = newNode;

    return previousLastIndex;
}


bool insertOrUpdate(HashNode** table, int key, int index, int k) {

    int idx = hashFunc(key);

    HashNode* current = table[idx];


    while (current != NULL) {

        if (current->key == key) {

            int previousIndex = addIndexTailAndGetPrevious(&(current->indices), index);
            int currentIndex = index;

            if (abs(previousIndex - index) <= k)
                return true;

            return false;

        }

        current = current->next;
    }

    // if key doesnot exist, create new node
    HashNode* newNode = malloc(sizeof(HashNode));

    newNode->key = key;
    newNode->indices = NULL;

    int prev = addIndexTailAndGetPrevious(&(newNode->indices), index);

    newNode->next = table[idx];
    table[idx] = newNode;

    return false;


}


bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    

    HashNode* table[TABLE_SIZE] = {NULL};

    bool status;

    // insert in the hashmap as key-value pair. 
    // Where key is the value of the array and value is the indices of the array
    for (int i = 0; i < numsSize; i++) {
        status = insertOrUpdate(table, nums[i], i, k);

        if (status)
            return status;

    }
    return false;

}


int main (void) {


    // Take the array size as input
    int arraySize;

    printf("Enter array size\n");
    scanf("%d", &arraySize);

    int nums[arraySize];

    // Take array elements as input
    for (int i = 0; i < arraySize; i++)
        scanf("%d ", &nums[i]);

    
    // Take an integer input
    int k;

    scanf("%d", &k);

    bool status = containsNearbyDuplicate(nums, arraySize, k);

    if (status)        
        printf("true");

    else
        printf("false");


    return 0;

}

