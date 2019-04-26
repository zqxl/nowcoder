#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>

float dis(int x1, int y1, int x2, int y2) {
	return sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
}

int main() {
	int p[7][2] = { 0 };

	while (~scanf("%d%d", &(p[1][0]), &(p[1][1]))) {
		int map[6] = { 0 };
		int route[5] = { 0 }, visted = 0;

		for (int i = 2; i < 6; i++) {
			for (int j = 0; j < 2; j++) {
				scanf("%d", &p[i][j]);
			}
		}
		
		double mindis = 999999;
		for (int i1 = 1; i1 < 6; i1++) {
			for (int i2 = 1; i2 < 6; i2++) {
				if (i2 != i1)
					for (int i3 = 1; i3 < 6; i3++) {
						if (i3 != i1 && i3 != i2)
							for (int i4 = 1; i4 < 6; i4++) {
								if (i4 != i1 && i4 != i2 && i4 != i3)
									for (int i5 = 1; i5 < 6; i5++) {
										if (i5 != i1 && i5 != i2 && i5 != i3 && i5 != i4) {
											route[0] = i1;
											route[1] = i2;
											route[2] = i3;
											route[3] = i4;
											route[4] = i5;

											float t = 0;
											t += dis(p[route[0]][0], p[route[0]][1], p[0][0], p[0][1]);
											for (int j = 0; j <= 5; j++) {
												t += dis(p[route[j]][0], p[route[j]][1], p[route[j] + 1][0], p[route[j] + 1][1]);
											}
											mindis = mindis > t ? t : mindis;
										}
									}
							}
					}
			}
		}
		printf("%d\n", (int)mindis);
	}
	return 0;
}