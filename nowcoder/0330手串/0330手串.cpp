#include<stdio.h>
#include<malloc.h>

int main() {
	int n, m, c;
	while (~scanf("%d%d%d", &n, &m, &c)) {
		// ��ά���飬����n�����飬ÿ������Ϊһ��
		int **data = (int **)calloc(n, sizeof(int *));
		// һλ���飬��ʾÿһ�еĴ��鶼�м�����ɫ
		int *datasize = (int *)malloc(sizeof(int) * n);
		// ѭ������ÿһ��
		for (int i = 0; i < n; i++) {
			// ����һ�еĵ�һ��Ԫ��
			scanf("%d", datasize + i);
			data[i] = (int *)malloc(sizeof(int) * datasize[i]);
			// ����һ�е�ÿһ��Ԫ��
			for (int j = 0; j < datasize[i]; j++) {
				scanf("%d", &data[i][j]);
			}
		}

		// map[x]��		
		int map[51] = { 0 };
		int iis = 0;
		// ��ʼѭ���ж�
		for (int i = 0; i < n; i++) {
			// ɾ��ǰһ�е�ͳ��
			if (i > 0) {
				for (int j = 0; j < datasize[i - 1]; j++) {
					// �����1��ɾ������2����0�ͱ���
					map[data[i - 1][j]] = map[data[i - 1][j]] == 1 ? 0 : map[data[i - 1][j]];
				}
				
				// �����һ��ͳ������
				iis = i + m - 1;
				iis = iis > n ? (iis%n) : iis;
				for (int j = 0; j < datasize[iis]; j++) {
					map[data[iis][j]]++;
				}

			}
			else {
				for (int ii = i; ii < i + m; ii++) {
					// ��iis������0-��n-1����Χ��
					iis = ii< n ? ii : ii%n;
					for (int j = 0; j < datasize[iis]; j++) {
						map[data[iis][j]]++;
					}
				}
			}
		}

		// ͳ��
		int res = 0;
		for (int i = 1; i < 51; i++) {
			if (map[i] > 1) {
				res++;
			}
		}
		printf("%d\n", res);

		// free����Ҫ
		for (int i = 0; i < n; i++) {
			free(data[i]);
		}
		free(data);
		free(datasize);
	}
	return 0;
}