#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void invertstr(char *s, int n) {
	for (int i = 0; i < n / 2; i++) {
		s[i] = s[i] ^ s[n - i - 1];
		s[n - i - 1] = s[i] ^ s[n - i - 1];
		s[i] = s[i] ^ s[n - i - 1];
	}
}

//void invertstr(char *s, int n) {
//	for (int i = 0; i < n / 2; i++) {
//		char t = s[i];
//		s[i] = s[n - i - 1];
//		s[n - i - 1] = s[i];
//	}
//}


int main() {
	char s[129] = {};
	int n = 0;
	while (~scanf("%d", &n)) {
		scanf("%s", s);
		int sl = strlen(s);

		for (int i = 0; i < n; i++) {
			char t[9] = {};
			if (s[i * 9] == '1') {
				strncpy(t, &s[i * 9] + 1, 8);
				printf("%s", t);
			}
			else {
				strncpy(t, &s[i * 9] + 1, 8);
				invertstr(t,8);
				printf("%s", t);
			}
			if(i!=n-1)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}