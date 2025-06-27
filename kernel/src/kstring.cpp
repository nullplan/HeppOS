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


#include <kstring.h>


size_t kstrlen(const char *pString) {
	if (pString == NULL)
		return 0;
	
	size_t i = 0;
	while (pString[i] != 0) {
		++i;
	}
	return i;
}

size_t kstrnlen(const char *pString, size_t pLength) {
	if (pString == NULL)
		return 0;
	
	size_t _Count = 0;
	while (_Count < pLength) {
		if (pString[_Count] == 0)
			break;
		++_Count;
	}
	return _Count;
}

char *kstrcpy(char *pDest, const char *pSource) {
	if (pDest == NULL)
		return NULL;
	if (pSource == NULL)
		return pDest;
	
	size_t i = 0;
	while (pSource[i] != 0) {
		pDest[i] = pSource[i];
		++i;
	}
	pDest[i] = 0;
	return pDest;
}

char *kstrncpy(char *pDest, const char *pSource, size_t pLength) {
	if (pDest == NULL)
		return NULL;
	if (pSource == NULL)
		return pDest;

	size_t i = 0;
	while (i < pLength) {
		pDest[i] = pSource[i];
		if (pSource[i] == 0)
			break;
		++i;
	}
	while (i < pLength) {
		pDest[i] = 0;
		++i;
	}
	return pDest;
}

int32_t kstrcmp(const char *pString1, const char *pString2) {
	size_t i = 0;
	while ((pString1[i] == pString2[i]) && (pString1[i] != 0)) {
		++i;
	}
	return pString1[i] - pString2[i];
}


int32_t kstrncmp(const char *pString1, const char *pString2, size_t pLength) {
	size_t i = 0;
	while ((pString1[i] == pString2[i]) && (pString1[i] != 0)) {
		if (i >= pLength)
			break;
		++i;
	}
	return pString1[i] - pString2[i];
}


int32_t kstricmp(const char *pString1, const char *pString2) {
	size_t i = 0;
	while ((kto_lower(pString1[i]) == kto_lower(pString2[i])) && (pString1[i] != 0)) {
		++i;
	}
	return pString1[i] - pString2[i];
}

int32_t kstrnicmp(const char *pString1, const char *pString2, size_t pLength) {
	size_t i = 0;
	while ((kto_lower(pString1[i]) == kto_lower(pString2[i])) && (pString1[i] != 0)) {
		if (i >= pLength)
			break;
		++i;
	}
	return pString1[i] - pString2[i];
}


char *kstrcat(char *pDest, const char *pSource) {
	if (pDest == NULL)
		return NULL;
	if (pSource == NULL)
		return pDest;
	
	char *_target = pDest + kstrlen(pDest);
	size_t i = 0;
	while (pSource[i] != 0) {
		_target[i] = pSource[i];
		++i;
	}
	return pDest;
}


char *kstrncat(char *pDest, const char *pSource, size_t pLength) {
	if (pDest == NULL)
		return NULL;
	if (pSource == NULL)
		return pDest;

	char *_target = pDest + kstrlen(pDest);
	size_t i = 0;
	while ((pSource[i] != 0) && (i < pLength)) {
		_target[i] = pSource[i];
		++i;
	}
	while (i < pLength) {
		pDest[i] = 0;
		++i;
	}
	return pDest;
}

char *kstrchr(const char *pSource, char pChar) {
	size_t i = 0;
	while (pSource[i] != 0) {
		if (pSource[i] == pChar)
			return (char*)&pSource[i];
		++i;
	}
	return NULL;
}

char *kstrrchr(const char *pSource, char pChar) {
	size_t i = kstrlen(pSource) - 1;
	while (i > 0) {
		if (pSource[i] == pChar)
			return (char*)&pSource[i];
		--i;
	}
	return NULL;	
}



char *kstrpbrk(char *pSource, const char *pDelimiter) {
	size_t i = 0;
	size_t _DelimiterLength = kstrlen(pDelimiter);
	while (pSource[i] != 0) {
		for (size_t k = 0; k < _DelimiterLength; ++k) {
			if (pSource[i] == pDelimiter[k]) {
				return &pSource[i];
			}
		}
		++i;
	}
	return NULL;
}

const char *kstrpbrk(const char *pSource, const char *pDelimiter) {
	size_t i = 0;
	size_t _DelimiterLength = kstrlen(pDelimiter);
	while (pSource[i] != 0) {
		for (size_t k = 0; k < _DelimiterLength; ++k) {
			if (pSource[i] == pDelimiter[k]) {
				return &pSource[i];
			}
		}
		++i;
	}
	return NULL;
}

char *kstrnpbrk(char *pSource, const char *pDelimiter, size_t pLength) {
	size_t i = 0;
	size_t _DelimiterLength = kstrlen(pDelimiter);
	while ((pSource[i] != 0) && (i < pLength)) {
		for (size_t k = 0; k < _DelimiterLength; ++k) {
			if (pSource[i] == pDelimiter[k]) {
				return &pSource[i];
			}
		}
		++i;
	}
	return NULL;
}

const char *kstrnpbrk(const char *pSource, const char *pDelimiter, size_t pLength) {
	size_t i = 0;
	size_t _DelimiterLength = kstrlen(pDelimiter);
	while ((pSource[i] != 0) && (i < pLength)) {
		for (size_t k = 0; k < _DelimiterLength; ++k) {
			if (pSource[i] == pDelimiter[k]) {
				return &pSource[i];
			}
		}
		++i;
	}
	return NULL;
}



size_t kstrspn(const char *pSource, const char *pDelimiter) {
	size_t i = 0;
	size_t k = 0;
	while (pSource[i] != 0) {
		for (k = 0; k < kstrlen(pDelimiter); ++k) {
			if (pSource[i] == pDelimiter[k])
				break;
		}
		if (k >= kstrlen(pDelimiter))
			break;
		++i;
	}
	return i;
}

size_t kstrnspn(const char *pSource, const char *pDelimiter, size_t pLength) {
	size_t i = 0;
	size_t k = 0;
	while ((pSource[i] != 0) && (i < pLength)) {
		for (k = 0; k < kstrlen(pDelimiter); ++k) {
			if (pSource[i] == pDelimiter[k])
				break;
		}
		if (k >= kstrlen(pDelimiter))
			break;
		++i;
	}
	return i;
}


size_t kstrcspn(const char *pSource, const char *pDelimiter) {
	size_t i = 0;
	size_t k = 0;
	while (pSource[i] != 0) {
		for (k = 0; k < kstrlen(pDelimiter); ++k) {
			if (pSource[i] == pDelimiter[k])
				break;
		}
		if (k < kstrlen(pDelimiter))
			break;
		++i;
	}
	return i;
}

size_t kstrncspn(const char *pSource, const char *pDelimiter, size_t pLength) {
	size_t i = 0;
	size_t k = 0;
	while ((pSource[i] != 0) && (i < pLength)) {
		for (k = 0; k < kstrlen(pDelimiter); ++k) {
			if (pSource[i] == pDelimiter[k])
				break;
		}
		if (k < kstrlen(pDelimiter))
			break;
		++i;
	}
	return i;
}



char kto_lower(char pChar) {
	if ((pChar > 0x40) && (pChar < 0x5B)) {
		return pChar + 0x20;
	}
	return pChar;
}

char kto_upper(char pChar) {
	if ((pChar > 0x60) && (pChar < 0x7B)) {
		return pChar - 0x20;
	}
	return pChar;
}



char *kitoa(int64_t pValue, char *pString, uint32_t pBase)
{
	int i = 0;
	bool isNegative = false;
	
	/* Handle 0 explicitly, otherwise empty string is
	* printed for 0 */
	if (pValue == 0) {
		pString[i++] = '0';
		pString[i] = '\0';
		return pString;
	}
	
	// In standard itoa(), negative numbers are handled
	// only with base 10. Otherwise numbers are
	// considered unsigned.
	if (pValue < 0 && pBase == 10) {
		isNegative = true;
		pValue = -pValue;
	}
	
	// Process individual digits
	while (pValue != 0) {
		int rem = pValue % pBase;
		pString[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		pValue = pValue / pBase;
	}
	
	// If number is negative, append '-'
	if (isNegative)
		pString[i++] = '-';
	
	pString[i] = '\0'; // Append string terminator
	
	// Reverse the string
	kreverse(pString);
 
	return pString;
}

char *kutoa (uint64_t pNumber, char *pString, uint32_t pBase) {
  const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
  int i, j;
  unsigned remainder;
  char c;
  
  /* Check base is supported. */
  if ((pBase < 2) || (pBase > 36))
    { 
      pString[0] = '\0';
      return NULL;
    }  
    
  /* Convert to string. Digits are in reverse order.  */
  i = 0;
  do 
    {
      remainder = pNumber % pBase;
      pString[i++] = digits[remainder];
      pNumber = pNumber / pBase;
    } while (pNumber != 0);  
  pString[i] = '\0'; 
  
  /* Reverse string.  */
  for (j = 0, i--; j < i; j++, i--)
    {
      c = pString[j];
      pString[j] = pString[i];
      pString[i] = c; 
    }       
  
  return pString;
}

void kreverse(char *pString)
{
    int start = 0;
    int end = kstrlen(pString) - 1;
    while (start < end) {
        char temp = pString[start];
        pString[start] = pString[end];
        pString[end] = temp;
        end--;
        start++;
    }
}



#ifdef __cplusplus
extern "C" {
#endif


void *memchr(const void *pSource, int8_t pValue, size_t pSize) {
	uint64_t i;
	if (pSize == 0)
		return NULL;
	while (i < pSize) {
		if (((int8_t*)pSource)[i] == pValue) {
			return &((int8_t*)pSource)[i];
		}
		++i;
	}
	return NULL;
}

int32_t memcmp(const void *a, const void *b, size_t length)
{
	const uint8_t *_a = (const uint8_t*)a;
	const uint8_t *_b = (const uint8_t*)b;
	
	for (size_t i = 0; i < length; i++)
	{
		if (_a[i] < _b[i]) {
			return -1;
		} else if (_a[i] > _b[i]) {
			return 1; 
		}
	}
	return 0;
}

void *memcpy(void *dest, const void *src, size_t length)
{
	uint8_t *_target = (uint8_t*)dest;
	for (size_t i = 0; i < length; i++)
	{
		_target[i] = ((uint8_t*)src)[i];
	}
	return dest;
}

void *memmove(void *dest, const void *source, size_t length)
{
	uint8_t *_target = (uint8_t*)dest;
	if (dest < source) 
	{
		for (size_t i = 0; i < length; i++)
		{
			_target[i] = ((uint8_t*)source)[i];
		}
	} else {
		for (size_t i = length; i != 0; i--)
		{
			_target[i-1] = ((uint8_t*)source)[i-1];
		}		
	}
	return dest;
}

void *memset(void *s, int8_t value, size_t length)
{
	uint8_t *_target = (uint8_t*)s;
	for (size_t i = 0; i < length; i++)
	{
		_target[i] = (uint8_t) value;
	}
	return s;
}


#ifdef __cplusplus
}
#endif
