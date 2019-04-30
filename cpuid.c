#include "header.h"
void cpuid (cpuid_t *st, uint32_t eax, uint32_t ecx) {
	
	__asm__ __volatile__ (
			"push %%rbx \n\t"
			"push %%rdx \n\t"
			
			"cpuid \n\t"
			"mov %%eax, 0x00(%[st])\n\t"
			"mov %%ebx, 0x04(%[st])\n\t"
			"mov %%ecx, 0x08(%[st])\n\t"
			"mov %%edx, 0x0c(%[st])\n\t"
			"pop %%rdx\n\t"
			"pop %%rbx\n\t"
		: "+a"(eax), "+c"(ecx)
		: [st]"D"(st)
		:"memory"
		);

}





