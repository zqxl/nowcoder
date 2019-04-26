#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	while (~scanf("%d", &n)) {
		int **data = (int**)malloc((n - 1) * sizeof(int*));
		for (int i = 0; i < n - 1; i++) {
			data[i] = (int*)malloc(2 * sizeof(int));
			scanf("%d%d", data[i], data[i] + 1);
		}
		
		//// 构建地图
		//int **map = (int**)malloc((n+1) * sizeof(int*));
		//for (int i = 0; i < n+1; i++) {
		//	map[i] = (int*)calloc((n+1), sizeof(int));
		//}
		//for (int i = 0; i < n - 1; i++) {
		//	map[data[i][0]][data[i][1]] = 1;
		//	map[data[i][1]][data[i][0]] = 1;
		//}

		//// 开始模拟
		//int wait = 0;
		//for (int j = 0; j < n - 1; j++) {
		//	int count = -1;
		//	for (int i = 0; i < n - 1; i++) {
		//		count += map[i][j];
		//	}
		//	wait += count;
		//}



		printf("%d\n", n - 2);
	}
	return 0;
}