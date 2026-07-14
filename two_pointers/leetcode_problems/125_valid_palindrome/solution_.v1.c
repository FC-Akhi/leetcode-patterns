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
* Approach (v1 solution):
* 1. Count how many non-alphanumeric characters exist in the input string.
* 2. Create a temporary string that stores only alphanumeric characters.
* 3. Convert all letters in the temporary string to lowercase.
* 4. Use two pointers to check whether the temporary string is a palindrome.
*
* Improvement:
* - Did some clean up and reduced some unnecessary if statements
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


// Count the number of non-alphanumeric characters in the string.
// These characters will be ignored later in the process.
int countNonAlphaNeu(const char *s) {

    int length = strlen(s);
    int count = 0;

    for (int i = 0; i < length; i++) {

        // If the character is not a letter or digit, count it.
        if (!isalnum(s[i])) {
            count++;
        }
    }

    return count;
}



bool isPalindrome(const char *s) {

    // Count characters that should be removed.
    int count = countNonAlphaNeu(s);

    // Get the length of the original input string.
    int length = strlen(s);


    // The cleaned string will contain only alphanumeric characters.
    int temp_size = length - count;


    // Create a temporary character array.
    // +1 is needed for the null terminator '\0'.
    char temp[temp_size + 1];


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



    bool status = true;

    // Use two pointers to compare characters from both ends.
    int left = 0;
    int right = strlen(temp) - 1;


    if (right < 0)
        right = 0;

    
    // Iterate temp string characters from backward and forward
    while (left != right && left < right) {

        // If characters from both ends do not match,
        // then the string is not a palindrome.
        if (temp[left] != temp[right]) {
        
            return false;
        
        }

        left++;
        right--;

    }

    // Return the status if the string is palindrome or not
    return status;


}



int main() {


    // Test input string
    char s [] = {"-1"};
                    
    bool status = isPalindrome(s);


    // If status is true
    if (status)
        printf("true\n");

    // If status is false        
    else
        printf("false\n");

    return 0;
}