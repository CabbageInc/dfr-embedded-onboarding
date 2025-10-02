#include <stdio.h>
#include <stdint.h>

int main(){
    printf("Hello World!\r\n");
    
    uint8_t num = 255;
    uint8_t *num_p = &num;

    printf("The integer number is %d.\r\n", num);
    printf("The hexadecimal number is 0x%X.\r\n", *num_p);
    printf("The size of the byte pointer is %d bytes.\r\n", (int)sizeof(num_p));

    printf("Application completed successfully.\r\n");
    return 0;
}