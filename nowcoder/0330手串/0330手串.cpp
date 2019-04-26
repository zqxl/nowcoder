#include<stdio.h>
#include<malloc.h>

int main() {
	int n, m, c;
	while (~scanf("%d%d%d", &n, &m, &c)) {
		// 二维数组，保存n个串珠，每个串珠为一行
		int **data = (int **)calloc(n, sizeof(int *));
		// 一位数组，表示每一行的串珠都有几种颜色
		int *datasize = (int *)malloc(sizeof(int) * n);
		// 循环输入每一行
		for (int i = 0; i < n; i++) {
			// 输入一行的第一个元素
			scanf("%d", datasize + i);
			data[i] = (int *)malloc(sizeof(int) * datasize[i]);
			// 输入一行的每一个元素
			for (int j = 0; j < datasize[i]; j++) {
				scanf("%d", &data[i][j]);
			}
		}

		// map[x]的		
		int map[51] = { 0 };
		int iis = 0;
		// 开始循环判断
		for (int i = 0; i < n; i++) {
			// 删除前一行的统计
			if (i > 0) {
				for (int j = 0; j < datasize[i - 1]; j++) {
					// 如果是1就删除，是2或者0就保留
					map[data[i - 1][j]] = map[data[i - 1][j]] == 1 ? 0 : map[data[i - 1][j]];
				}
				
				// 把最后一行统计入内
				iis = i + m - 1;
				iis = iis > n ? (iis%n) : iis;
				for (int j = 0; j < datasize[iis]; j++) {
					map[data[iis][j]]++;
				}

			}
			else {
				for (int ii = i; ii < i + m; ii++) {
					// 把iis限制在0-（n-1）范围内
					iis = ii< n ? ii : ii%n;
					for (int j = 0; j < datasize[iis]; j++) {
						map[data[iis][j]]++;
					}
				}
			}
		}

		// 统计
		int res = 0;
		for (int i = 1; i < 51; i++) {
			if (map[i] > 1) {
				res++;
			}
		}
		printf("%d\n", res);

		// free很重要
		for (int i = 0; i < n; i++) {
			free(data[i]);
		}
		free(data);
		free(datasize);
	}
	return 0;
}