// For bool, true, and false
#include <stdbool.h>

// For printf function
#include<stdio.h>

// For abs function
#include<stdlib.h>

void update_value(int *x) {
    *x = 100;
}



void process(int *arr, int n) {

    for (int i = 0; i < n; i++)
        arr[i] = arr[i] * 2;

}

int main (void) {


    int a = 10;

    int *ptr = &a;

    // dereferencing techniques
    printf("%d\n", *ptr);       // Go to the address stored in ptr and read the int value there.
                                // Most common widely used to derefer value in the address which pointer points


    printf("%d\n", ptr[0]);     // array subscript operator. Internally it is *(ptr + 0)
                                // *(ptr + 0) -> first look for (ptr + 0) which is same as ptr. Then *ptr same as before.
                                // this technique is used when pointer points a sequence/array. Not used for the case where pointer points to single variable.

    printf("%d\n", *(ptr + 0)); // This is less commonly used. expanded form of prt[0]

    *ptr = 20;

    printf("%d\n", *ptr);       
    printf("%d\n", ptr[0]);     
    printf("%d\n", *(ptr + 0)); 

    update_value(&a);

    printf("%d\n", *ptr);       


    printf("%d\n", *(ptr + 1));
    printf("%d\n", ptr[1]);




    int arr[] = {10, 20, 30};

    //int *pp = &arr; // Dont use &arr, Because &arr means address of the whole array object. Its type is int (*)[3]. 
                      // &arr means pointer to whole array of 3 ints

    int *pp = arr;    // arr name itself becomes pointer to first element. And its type is int *

    int *ppp = &arr[0]; // Above arr internally becomes address of first element with array index 0



    printf("%d\n", *pp);
    printf("%d\n", pp[0]);  // widely used technique
    printf("%d\n\n", *(pp + 0));


    process(arr, 3);

    printf("%d\n", pp[0]);  // widely used technique
    printf("%d\n", pp[1]);  // widely used technique
    printf("%d\n", pp[2]);  // widely used technique



    printf("%d\n", *ppp);
    printf("%d\n", ppp[0]);
    printf("%d\n\n", *(ppp + 0));

    
    // Less common but useful for fixed-width 2D arrays
    int (*pppp)[3] = &arr;

    printf("%d\n", (*pppp)[0]);


    int matrix[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    // int (*pt)[3] = &matrix;     //  warning: initialization of ‘int (*)[3]’ from incompatible pointer type ‘int (*)[2][3]’
    int (*pt)[3] = matrix;         // So using this 

    printf("%d\n", pt[0][0]);  // 10
    printf("%d\n", pt[1][2]);  // 60


    //int *ptt = matrix; // this will not work. Because matrix becomes a pointer of type int (*)[3]
                       // matrix itself is not a pointer.
                       // matrix is a 2D array.
                       //But when used in this expression, it decays to a pointer to its first row.


    // printf("%d\n", pt[0][0]);  // 10
    // printf("%d\n", pt[1][2]);  // 60


    return 0;
}
