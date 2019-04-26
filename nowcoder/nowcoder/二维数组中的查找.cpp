#include<stdio.h>
#include<malloc.h>

int max(int* nums, int s, int e) {
	int max = nums[s++];
	while (s < e) {
		max = max < nums[s] ? nums[s] : max;
		s++;
	}
	return max;
}

int main() {
	int sn = 0, on = 0;
	int *scores = NULL;
	while (scanf("%d%d", &sn, &on) != EOF) {
		scores = (int*)malloc(sizeof(int) * sn);
		for (int i = 0; i<sn; i++) {
			scanf("%d", &scores[i]);
		}

		char c;
		int a = 0, b = 0;
		while (on--) {
			//printf("%d command left\n", on);
			scanf(" %c%d%d", &c, &a, &b);
			if (c == 'Q') {
				int t = 0;
				if(b>=a)
					t = max(scores, a - 1, b);
				else
					t = max(scores, b - 1, a);
				printf("%d\n", t);
			}
			else {
				scores[a-1] = b;
			}
		}
		free(scores);
	}

	return 0;
}