#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* Function to perform three-way comparison on two ints
 * to sort them in ascending order.
 *
 * params:
 * a, const void *, cast to int internally, input to be compared
 * b, const void *, cast to int internally, reference to compare to
 *
 * return:
 * int, -1 if a<b, 1 if a>b, 0 otherwise
 */
int compare_ints_asc(const void *a, const void *b){
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;
    
    if(int_a>int_b) return 1;
    else if(int_a<int_b) return -1;
    else return 0;
}

/* Helper function to perform descending three-way comparison on
 * two integers. Negates the result of compare_ints_asc.
 *
 * Note:
 * This function cannot operate if compare_ints_asc is
 * not included.
 *
 * params:
 * a, const void *, input to be compared
 * b, const void *, reference to compare to
 *
 * return:
 * int 1 if a<b, -1 if a>b, 0 otherwise
 */
int compare_ints_desc(const void *a, const void *b){
    return -compare_ints_asc(a, b);
}

// helper function to display a pointer-style array on stdout
void print_nums(int *nums, size_t size){
    for(size_t i = 0; i<size; i++){
        printf("%d", nums[i]);
        if(i != size-1) printf(" ");
    }
    printf("\r\n");
}

int main(){
    // dynamically allocate heap memory for array of 20 ints
    size_t nums_size = 20;
    int *nums = malloc(nums_size*sizeof(int));

    for(size_t i = 0; i<nums_size; i++){
        nums[i] = i+1;
    }

    // sort nums array with qsort and three-way comparison function
    qsort(nums, nums_size, sizeof(int), compare_ints_desc);
    
    // display contents of nums array on stdout
    print_nums(nums, nums_size);

    // free up heap memory for nums array
    free(nums);

    // indicate successful completion
    printf("\nApplication completed successfully.\r\n");
    return 0;
}