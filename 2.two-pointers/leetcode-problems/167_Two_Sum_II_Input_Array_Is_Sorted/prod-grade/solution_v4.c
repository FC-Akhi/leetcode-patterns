#include "valid_palindrome.h"

#include<stdio.h>
#include <cassert>


void testLeetCodeExample() {

    const char s1 [] = {"A man, a plan, a canal: Panama"};

    const char s2 [] = {"race a car"};

    const char s3 [] = {" "};

    assert(isPalindrome(s1) == 1);
    assert(isPalindrome(s2) == 0);
    assert(isPalindrome(s3) == 1);

}

void testSingleElement() {

    const char s1 [] = {"a"};

    assert(isPalindrome(s1) == 1);
}

void testAllPositiveNumbersOfDiffLength() {
    const char s1 [] = {"1"};
    const char s2 [] = {"12"};
    const char s3 [] = {"121"};

    assert(isPalindrome(s1) == 1);
    assert(isPalindrome(s2) == 0);
    assert(isPalindrome(s3) == 1);
}

void testAllNegativeNumbers() {
    const char s1 [] = {"-1-2-2-1"};

    assert(isPalindrome(s1) == 1);
}

void testInvalidCharactersAndNumbers() {
    const char s1 [] = {"$^%%"};

    const char s2 [] = {"$^%%89"};

    const char s3 [] = {"$^%%99"};

    assert(isPalindrome(s1) == 1);
    assert(isPalindrome(s2) == 0);
    assert(isPalindrome(s3) == 1);
}


int main() {
    testLeetCodeExample();
    testSingleElement();
    testAllPositiveNumbersOfDiffLength();
    testAllNegativeNumbers();
    testInvalidCharactersAndNumbers();


    printf("All tests passed successfully.\n");

    return 0;
}