#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char s[1000] = {};
	int map[256] = {0};
	while (~scanf("%s", s)) {
		int sl = strlen(s);
		for (int i = 0; i < sl; i++) {
			if (map[s[i]] == 0) {
				printf("%c", s[i]);
				map[s[i]] = 1;
			}
		}
		printf("\n");
	}
	return 0;
}
