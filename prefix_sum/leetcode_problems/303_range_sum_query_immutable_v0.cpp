/* 
* Title: LeetCode 303 - Range Sum Query Immutable 
* Description: 
* This program implements the NumArray class using a 
* brute-force approach. 
* The class stores an input vector and answers range sum queries. 
* For each query, it calculates the sum from left index to right index directly.
*
* Approach:
* Brute-force range sum calculation. 
*
* Author: F.C.Fahi 
* Date: 04 June 2026 
*/

#include<stdio.h>
#include<vector>


// Leetcode part starts here
/* 
* Class: NumArray 
* Description: 
* This class stores an integer array using std::vector<int>. 
* It provides a method called sumRange() to calculate the sum of elements 
* between two given indices: left and right. 
* 
* Input: 
*   The class receives a vector of integers through its constructor. 
* 
* Output: 
*   The constructor does not return anything. 
* The sumRange() method returns an integer sum. 
* 
* Approach: 
* This is a brute-force approach. 
* For each sumRange(left, right) query, the method loops from left to right 
* and adds each element one by one. 
*/
class NumArray {

public:
    // Class variable, vector int type 
    std::vector<int> nums;
    
    /*
    * This constructor initializes the NumArray object. 
    * It receives the input vector and stores a copy of it in the class variable. 
    */
    NumArray(std::vector<int>& nums) {

        // Copies the constructor input vector into the class variable 
        // Left side this->nums means the class member variable 
        // Right side nums means the constructor parameter
        this->nums = nums;
    }


    /* 
    * Method: sumRange 
    * Description: 
    * This method calculates the sum of elements from index left to index right.
    * Both left and right indices are included in the sum. 
    * 
    * Parameters: 
    *   left - Starting index of the range. 
    *   right - Ending index of the range. 
    * 
    * Output: 
    *   Returns the calculated sum as an integer. 
    */
    int sumRange(int left, int right) {
        
        // Declares a variable to store the range sum 
        // Initially, the sum is 0
        int sum = 0;

        // Loops from the left index to the right index
        // The condition i <= right means the right index is included
        // The condition i <= right also means left is always smaller or equal
        // than right
        for(int i = left; i <= right; i++) {

            sum = sum + this->nums[i];

        }

        return sum;
    }

};
// Leetcode part ends here


// For my own test 
/* 
* Function: main 
* Description: 
* This function is used only for local testing. 
* LeetCode does not require the main function. 
* 
* Input: 
*   A vector is manually created: 
*   {-2, 0, 3, -5, 2, -1} 
* 
* Process: 
*   1. Create a NumArray object using the input vector. 
*   2. Call sumRange() with different left and right values. 
*   3. Print the returned sums. 
*/
int main (void) {

    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};


    /* 
    * Creates a normal NumArray object without using new.
    * The input vector nums is passed to the constructor.
    * The constructor stores a copy of nums inside the object.
    * Since this is a normal object, memory is managed automatically.
    * The object will be destroyed automatically when it goes out of scope.
    */
    NumArray numArray(nums);

    printf("%d\n", numArray.sumRange(0, 2));
    printf("%d\n", numArray.sumRange(2, 5));
    printf("%d\n", numArray.sumRange(0, 5));

    

    /* 
    * Creates a NumArray object dynamically using new.
    * Because new is used, numArrayPtr is a pointer to a NumArray object.
    * The input vector nums is passed to the constructor.
    * The constructor stores a copy of nums inside the object.
    * Since the object is created with new, it must be deleted manually.
    */
    NumArray* numArrayPtr = new NumArray(nums);

    printf("%d\n", numArrayPtr->sumRange(0, 2));
    printf("%d\n", numArrayPtr->sumRange(2, 5));
    printf("%d\n", numArrayPtr->sumRange(0, 5));

    delete numArrayPtr;


    return 0;
}