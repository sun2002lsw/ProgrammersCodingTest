#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* s) {
	size_t strLen = strlen(s);
	char* answer;

	if (strLen % 2)
	{
		answer = (char*)malloc(2);

		answer[0] = s[strLen / 2];
		answer[1] = '\0';
	}
	else
	{
		answer = (char*)malloc(3);

		answer[0] = s[strLen / 2 - 1];
		answer[1] = s[strLen / 2];
		answer[2] = '\0';
	}

	return answer;
}

int main()
{
	solution("ABCD");

	return 0;
}
