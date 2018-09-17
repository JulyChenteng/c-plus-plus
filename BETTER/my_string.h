#ifndef _MY_STRING_H
#define _MY_STRING_H

size_t  my_strlen(const char *);
void  	my_strcpy(char *dest, const char *src);
void 	my_strcat(char *dest, const char *src);
int 	my_strcmp(const char *str1, const char *str2);

void* 	my_memcpy(void *dest, const void *src, size_t n);
void* 	my_memmove(void *dest, const void *src, size_t n);
int   	my_memcmp(const void *s1, const void *s2, size_t n);
void* 	my_memset(void *dest, int c, size_t n);

#endif 

