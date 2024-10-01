#include "revert_string.h"
#include <string.h>
#include <stdio.h>

void RevertString(char *str)
{
	int length = strlen(str);
	printf("%d\n",length);
	for (int i = 0; i < length / 2; i++){
		char temp = str[i];
		str[i] = str[length - i - 1]; // Replace the current character with the matching character from the end of the string
		str[length - i - 1] = temp;
	}
}