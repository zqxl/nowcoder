#include<stdio.h>
int main() {
	int x;

	while (~scanf("%d", &x)) {
		int nums[1000] = { 0 };
		int j=0,i=-1;
		for (int count = x; count != 0; ) {
			i = (i + 1) % x;
			if (nums[i] == 0) {
				if (j == 2){
					nums[i] = 1;
					count--;
				}
				j = (j + 1) % 3;
			}
		}
		printf("%d\n", i);
	}
	return 0;
}