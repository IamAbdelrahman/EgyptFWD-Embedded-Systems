#include "dio.h"

int main(void)
{   
    DIO_init (PORT_A, 0, OUT);
    DIO_write (PORT_A, 0, HIGH);
    
    DIO_init (PORT_B, 1, IN);
    DIO_write (PORT_B, 1, LOW);
} 

