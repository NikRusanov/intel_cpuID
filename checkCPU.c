#include "header.h"

#ifdef __cplusplus
extern "C"
{
#endif

	int checkCPUID()
	{
		register int result;
		
	__asm__ __volatile__
		(
			"pushf \n\t"
			"pop %%rax\n\t"
			"OR $0x200000,%%eax\n\t"
			"push %%rax\n\t"
			"popf \n\t"
			"pushf \n\t"
			"pop %%rax\n\t"
			"test $0x200000, %%eax\n\t"
			"jz 100f\n\t"
				"and $0xffdfffff, %%eax\n\t"
				"push %%rax\n\t"
				"popf \n\t"
				"pushf \n\t"
				"pop %%rax\n\t"
				"test $0x200000, %%eax\n\t"
				"mov $1, %%eax\n\t"
				"jmp 200f\n\t"
			"100:\n\t"	
				"xor %%eax, %%eax\n\t"
			
			"200:\n\t" 
				:"+q"(result)   ::"cc", "memory"
		);
			return result;
	}
		#ifdef __cplusplus
}
#endif
