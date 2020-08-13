#include <stddef.h>
#include <assert.h>
#include "my_string.h"

size_t my_strlen(const char * str)
{
	assert(str != NULL);

	/*
	const char *pstr = str;
	for (; *pstr != '\0'; pstr++)
		;

	return (pstr - str);
	*/
	
	if (*str == '\0')
		return 0;
	else
		return (my_strlen(str+1) + 1);
}

void  my_strcpy(char *dest, const char *src)
{
	assert(dest != NULL && src != NULL);

	char *pdest = dest;
	const char *psrc = src;
	
	for (pdest = dest; (*pdest++ = *psrc++) != '\0';)
		;
	
	/*
	while (*psrc != '\0')
	{
		*pdest++ = *psrc++;
	}

	*pdest = '\0';
	*/
}

void my_strcat(char *dest, const char *src)
{
	assert(dest != NULL && src != NULL);

	char *pdest = dest;
	const char *psrc = src;

	
	for (; *pdest != '\0'; pdest++)
		;

	for (; (*pdest = *psrc) != '\0'; pdest++, psrc++)
		;
	
	/*
	while (*pdest != '\0')
		pdest++;

	while ((*pdest++ = *psrc++) != '\0')
		;
	*/
}

int my_strcmp(const char *str1, const char *str2)
{
	assert(str1 != NULL && str2 != NULL);

	const char *pstr1 = str1;
	const char *pstr2 = str2;

	for (; *pstr1 == *pstr2; pstr1++, pstr2++)
		if (*pstr1 == '\0')
			return 0;

	return (*(unsigned char*)pstr1 > *(unsigned char*)pstr2 ? 1 : -1);

	/*
	int result = 0;
	while (*pstr1 != '\0' || *pstr2 != '\0')
	{
		result = *pstr1 - *pstr2;
		if (result != 0)
			break;

		pstr1++;
		pstr2++;
	}

	if (result > 0)
		result = 1;
	else if (result < 0)
		result = -1;

	return result;
	*/
}

//memcpy函数未考虑内存重叠问题，慎用！
void* my_memcpy(void *dest, const void *src, size_t n)
{
	assert(dest != NULL && src != NULL);

	char *pdest = (char *)dest;
	const char *psrc = (const char *)src;

	for (; n > 0; *pdest++, *psrc++, --n)
		*pdest = *psrc;
	
	return (void*)dest;
}

//memmove函数解决了内存重叠问题，建议使用！
void* my_memmove(void *dest, const void *src, size_t n)
{	
	assert(dest != NULL && src != NULL);

	char *pdest = (char *)dest;
	const char *psrc = (const char *)src;

	if (psrc > pdest || pdest > psrc + n)
		for (; n > 0; n--)
			*pdest++ = *psrc++;
	else
		for (pdest += n, psrc += n; n > 0; n--)
			*--pdest = *--psrc;

	return dest;
}

int my_memcmp(const void *s1, const void *s2, size_t n)
{
	assert(s1 != NULL && s2 != NULL);

	const unsigned char *ps1 = (const unsigned char *)s1;
	const unsigned char *ps2 = (const unsigned char *)s2;

	for (; n > 0; *ps1++, *ps2++, n--)
		if (*ps1 != *ps2)
			return (*ps1 > *ps2 ? 1 : -1);

	return 0;
}

void* my_memset(void *dest, int c, size_t n)
{
	assert(dest != NULL);

	const unsigned char uc = c;
	char *pdest = (char *)dest;

	for (; n > 0; pdest++, n--)
		*pdest = uc;

	return dest;
}

