#include "valid_palindrome.h"

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
