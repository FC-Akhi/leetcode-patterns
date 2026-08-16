/* 
* Title: solution_v0
*
* Description:
* A phrase is a palindrome if, after converting all uppercase letters into
* lowercase letters and removing all non-alphanumeric characters, it reads
* the same forward and backward.
*
* Alphanumeric characters include letters and numbers.
*
* Given a string s, return true if it is a palindrome, otherwise return false.
*
* Approach (v2 solution):
* 1. Create a temporary string that stores only alphanumeric characters getCleanAlphaNeumericString().
* 2. Convert all letters in the temporary string to lowercase getCleanAlphaNeumericString().
* 3. Use two pointers to check whether the temporary string is a palindrome isPalindrome().
*
* Improvement:
* - Removed the non-alphaneumeric total character counter
* - Declared the temp array size same as input string
*
* Author: F.C.Fahi 
* Date: 14 June 2026 
*/


#include <stdio.h>

// For strlen()
#include <string.h>

// For bool, true, and false
#include <stdbool.h>

// For isalnum() and tolower()
#include <ctype.h>



// Get clean temp string with only alpha neumeric characters
// And return the length of the temp
int getCleanAlphaNeumericString(
    char *temp, 
    const char *s
) {

    // h is the index used for inserting characters into temp.
    int h = 0;

    
    // Build the cleaned string.
    // Keep only alphanumeric characters and convert upper cases to lowercase (if any).
    for (int i = 0; s[i] != '\0'; i++) {

        // Check whether the current character is a letter or digit.
        // If yes then make upper case to lower case and insert
        // otherwise keep unchanged and insert
        if (isalnum(s[i])) {

            temp[h] = tolower(s[i]);
            h++;
        }
    }
    // End the temporary character array as a valid C string.
    temp[h] = '\0';

    return h;

}



bool isPalindrome(
    const char *s
) {


    // Get the length of the original input string.
    int length = strlen(s);


    // Create a temporary character array.
    // +1 is needed for the null terminator '\0'.
    char temp[length+1];


    // Get clean alpha neumeric string
    int h = getCleanAlphaNeumericString(temp, s);
    

    // Use two pointers to compare characters from both ends.
    int left = 0;
    int right = h - 1;


    if (right < 0)
        right = 0;

    
    // Iterate temp string characters from backward and forward
    while (left < right) {

        // If characters from both ends do not match,
        // then the string is not a palindrome.
        if (temp[left] != temp[right]) {
        
            return false;
        
        }

        left++;
        right--;

    }

    // Return the status if the string is palindrome or not
    return true;


}



int main() {


    // Test input string
    char s [] = {"^^89"};
                    
    bool status = isPalindrome(s);


    // If status is true
    if (status)
        printf("true\n");

    // If status is false        
    else
        printf("false\n");

    return 0;
}