#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t value = 0x44332211;
    printf("Size of value : %d byte\n", sizeof(value));
    printf("Address space before conversion : 0x%x\n", value);
    
    // Program to check the endianess
    char *r = (char*) &value;

    for(int i = 0; i<4; i++){
        printf("Address of 0x%x element : %d\n", r[i], &r[i]);
    }

    // Conversion of one endian to another

    uint32_t converted = 0;

    converted |= (0xff & value ) << 24;
    converted |= ((0xff << 8) & value) << 8; 
    converted |= ((0xff << 16)&value) >> 8; 
    converted |= ((0xff << 24) & value) >> 24; 

    printf("Converted address space is : 0x%x\n", converted);
    r = (char*) &converted;

    for (int i = 0; i < 4; i++)
    {
        printf("Address of 0x%x is : %d\n", r[i], &r[i]);
    }
    
    return 0;
}