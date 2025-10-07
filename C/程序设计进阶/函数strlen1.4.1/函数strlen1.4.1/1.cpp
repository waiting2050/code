#include <stdio.h>
#include <string.h>

size_t len(char* s) {
	int cnt = 0;
	for (; s[cnt] != '\0'; cnt++);
	return cnt;
}

int main() {
	char line[] = "hello";
	printf("len=%llu\n", len(line));
	printf("strlen=%llu\n", strlen(line));
	printf("sizeof_line=%llu", sizeof(line));

	return 0;
}