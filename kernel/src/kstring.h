
#ifndef HEADER_KSTRING
#define HEADER_KSTRING

#include <stddef.h>
#include <stdint.h>



size_t kstrlen(const char *pString) __attribute__ (( nothrow ));
size_t kstrnlen(const char *pString, size_t pLength) __attribute__ (( nothrow ));

char *kstrcpy(char *pDest, const char *pSource) __attribute__ (( nothrow ));
char *kstrncpy(char *pDest, const char *pSource, size_t pLength) __attribute__ (( nothrow ));

int32_t kstrcmp(const char *pString1, const char *pString2) __attribute__ (( nothrow ));
int32_t kstrncmp(const char *pString1, const char *pString2, size_t pLength) __attribute__ (( nothrow ));

int32_t kstricmp(const char *pString1, const char *pString2) __attribute__ (( nothrow ));
int32_t kstrnicmp(const char *pString1, const char *pString2, size_t pLength) __attribute__ (( nothrow ));

char *kstrcat(char *pDest, const char *pSource) __attribute__ (( nothrow ));
char *kstrncat(char *pDest, const char *pSource, size_t pLength) __attribute__ (( nothrow ));

char *kstrchr(const char *pSource, char pChar) __attribute__ (( nothrow ));
char *kstrrchr(const char *pSource, char pChar) __attribute__ (( nothrow ));

char *kstrpbrk(char *pSource, const char *pDelimiter) __attribute__ (( nothrow ));
const char *kstrpbrk(const char *pSource, const char *pDelimiter) __attribute__ (( nothrow ));
char *kstrnpbrk(char *pSource, const char *pDelimiter, size_t pLength) __attribute__ (( nothrow ));
const char *kstrnpbrk(const char *pSource, const char *pDelimiter, size_t pLength) __attribute__ (( nothrow ));

size_t kstrspn(const char *pSource, const char *pDelimiter) __attribute__ (( nothrow ));
size_t kstrnspn(const char *pSource, const char *pDelimiter, size_t pLength) __attribute__ (( nothrow ));

size_t kstrcspn(const char *pSource, const char *pDelimiter) __attribute__ (( nothrow ));
size_t kstrncspn(const char *pSource, const char *pDelimiter, size_t pLength) __attribute__ (( nothrow ));

char kto_lower(char pChar) __attribute__ (( nothrow ));
char kto_upper(char pChar) __attribute__ (( nothrow ));


void reverse(char str[], int length) __attribute__ (( nothrow ));
char* itoa(int64_t num, char* str, int base) __attribute__ (( nothrow ));
char* utoa(uint64_t num, char* str, int base) __attribute__ (( nothrow ));

#ifdef __cplusplus
extern "C" {
#endif 

void *memchr(const void *pSource, int8_t pValue, size_t pSize) __attribute__(( nothrow ));
int32_t memcmp(const void* pData1, const void* pData2, size_t pLength) __attribute__(( nothrow ));
void* memcpy(void *pDest, const void *pSource, size_t pLength) __attribute__(( nothrow ));
void* memmove(void *pDest, const void *pSource, size_t pLength) __attribute__(( nothrow ));
void* memset(void *pDest, int8_t pValue, size_t pLength) __attribute__(( nothrow ));

#ifdef __cplusplus
}
#endif

#endif

