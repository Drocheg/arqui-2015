#include <stdlib.h>

uint8_t streql(const char *s1, const char *s2) {
	while(*s1 != 0 && *s2 != 0) {
		if(*s1 != *s2) return 0;
		s1++;
		s2++;
	}
	return 1;
}

int32_t strcmp(const char *s1, const char *s2) {
	while(*s1 != 0 && *s2 != 0) {
		int diff = *s1 - *s2;
		if(diff != 0) return diff;
		s1++;
		s2++;
	}
	return *s1-*s2;
}

uint32_t strlen(const char *s) {
	uint32_t result = 0;
	while(*s != 0) {
		result++;
		s++;
	}
	return result;
}

int32_t indexOf(const char *needle, const char *haystack) {
	int hIndex, nIndex, nLen = strlen(needle);
	for(hIndex = 0, nIndex = 0; haystack[hIndex] != 0; hIndex++) {
		if(hIndex >= nLen) return -1;
		if(haystack[hIndex] == needle[nIndex]) {
			nIndex++;
			if(nIndex == nLen-1) {
				return hIndex-nLen;
			}
		}
		else {
			nIndex = 0;
		}
	}
	return -1;
}

char * toUpperStr(char *s) {
	int i;
	for(i = 0; *s != 0; s++) {
		s[i] = toUpperChar(s[i]);
	}
	return s;
}

char * toLowerStr(char *s) {
	int i;
	for(i = 0; *s != 0; s++) {
		s[i] = toLowerChar(s[i]);
	}
	return s;
}

char toUpperChar(char s) {
	if(s >= 'a' && s <= 'z') return s-32;
	else return s;
}

char toLowerChar(char s) {
	if(s >= 'A' && s <= 'Z') return s+32;
	else return s;
}