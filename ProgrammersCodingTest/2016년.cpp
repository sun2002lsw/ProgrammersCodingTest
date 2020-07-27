#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const char weekDay[7][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int DayOfWeek(int y, int m, int d)
{
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

	y -= m < 3;
	int yearDay = y + y / 4 - y / 100 + y / 400 + t[m - 1] + d;

	return yearDay % 7;
}

char* solution(int a, int b) {
	int day = DayOfWeek(2016, a, b);

	char* answer = (char*)malloc(4);
	strcpy(answer, weekDay[day]);

	return answer;
}
