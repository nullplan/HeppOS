/* 
    Copyright (C) 2025  Sebastian Hepp aka sebihepp

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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



void kreverse(char *pString) __attribute__ (( nothrow ));
char* kitoa(int64_t pNumber, char *pString, uint32_t pBase) __attribute__ (( nothrow ));
char* kutoa(uint64_t pNumber, char *pString, uint32_t pBase) __attribute__ (( nothrow ));



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

