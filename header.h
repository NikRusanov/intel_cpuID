
#ifndef HEADER_H
#define HEADER_H

#include <stdint.h>
#pragma pack(push,1)


typedef struct cpuid_t {
	uint32_t eax;
	uint32_t ebx;
	uint32_t ecx;
	uint32_t edx;
} cpuid_t;
#pragma pack(pop)


#ifdef __cplusplus
extern "C"
{
#endif
	extern int  checkCPUID();
	extern void cpuid (cpuid_t *st, uint32_t eax, uint32_t ecx);
#ifdef __cplusplus
}
#endif

#endif /* STRFUNC_H */
