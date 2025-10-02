#include <stdio.h>
#include <stdlib.h>

/* Function to print Fizz for multiples of 3,
 * and Buzz for multiples of 5. FizzBuzz for 
 * multiples of both.
 *
 * params:
 * n, integer, number to compute FizzBuzz of
 *
 * return:
 * none, output displayed on stdout
 */
void FizzBuzz(int n){
    if(n%3 == 0) printf("Fizz");
    if(n%5 == 0) printf("Buzz");
    printf("\r\n");
}

int main(){    
    // dynamically allocate heap memory for array of 20 ints
    int nums_size = 20;
    int *nums = malloc(nums_size*sizeof(int));

    // perform fizzbuzz on pointer-style array, nums
    printf("FizzBuzz of Array:\r\n");
    for(int i = 0; i<nums_size; i++){
        nums[i] = i+1;
        printf("FizzBuzz of %d: ", nums[i]);
        FizzBuzz(nums[i]);
    }

    // free up heap memory for nums array
    free(nums);

    // iterate from 1-30, perform fizzbuzz of current iteration count
    printf("\nFizzBuzz of for loop (1-30):\r\n");
    for(int i = 1; i<=30; i++){
        printf("FizzBuzz of %d: ", i);
        FizzBuzz(i);
    }

    // indicate successful completion
    printf("\nApplication completed successfully.\r\n");
    return 0;
}