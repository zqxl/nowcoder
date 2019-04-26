//https://www.nowcoder.com/test/question/d25162386a3140cbbe6dc071e1eb6ed6?pid=8537269&tid=22734737
#include<stdio.h>
#include<malloc.h>
int tarNum(int *data, int s, int e, int tar) {
	int count = 0;
	for (int i = s; i<e; i++) {
		if (data[i] == tar)
			count++;
	}
	return count;
}
int main() {
	int datanum = 0;
	while (~scanf("%d", &datanum)) {
		int *data = (int *)malloc(sizeof(int) * datanum);
		for (int i = 0; i<datanum; i++) {
			scanf("%d", data + i);
		}

		int opernum = 0;
		scanf("%d", &opernum);
		for (int i = 0; i<opernum; i++) {
			int s, e, tar;
			scanf("%d%d%d", &s, &e, &tar);
			int count = tarNum(data, s - 1, e, tar);
			printf("%d\n", count);
		}
		/*   free ºÜÖØÒª £¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡*/
		free(data);
	}
}