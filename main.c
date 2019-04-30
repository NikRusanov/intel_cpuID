#include "header.h"
#include <stdio.h>

void translate (uint32_t r)
{
    int i;
    for (i = 0; i < 4; i++, r>>=8) {
        putchar(r&0xff);
    }
}

int main() {
    uint32_t i;
	cpuid_t t;
    
    int check_id = checkCPUID();
	printf("cpuid flag = %d\n",check_id);
	if(check_id == 1) {
        cpuid(&t,0,0);
        printf("Highest Value For Basic Processor Information \t \t %d\n",t.eax);
        printf("Manufacturer \t\t");
        translate(t.ebx);
        translate(t.edx);
        translate(t.ecx);
        printf("\n");
        cpuid(&t,0x80000000,0);
        printf("\nMaximum Input Value For Exteneded Function CPUID Information \t\t 0x%x\n",t.eax);
        printf("Processor Brand String ");
        for ( i = 0x80000002; i <= 0x80000004; i++)
        {
            cpuid(&t, i, 0);
            translate(t.eax);
            translate(t.ebx);
            translate(t.ecx);
            translate(t.edx);
        }
      
        
       
        printf("\n");
        
    }
    
	return 0;
}
