/*
京东2018实习生招聘  C++开发工程师
27.编程题
路径规划（京东2016实习生真题）
http://exercise.acmcoder.com/quesexcuse?paperId=172

100%通过
*/

#include<stdio.h>

int main(){
	while (1) {
		char data[2][2];
		for (int i = 0;i < 2 ; i++) {
			for (int j = 0;  j < 2;j++) {
				data[i][j] = getchar();
				if (data[i][j] == EOF) {
					return 0;
				}
			}
			getchar();
		}

		// 当前坐标
		char cur[2] = { data[0][0], data[0][1] };
		// 记录走法: L = 1; D = -1;
		char record[16][2], step = 0;
		while (cur[0] != data[1][0] || cur[1] != data[1][1]) {
			record[step][0] = data[1][0] - cur[0] == 0 ? 0 :(data[1][0] - cur[0] >0 ? 1 : -1);
			cur[0] += record[step][0];

			record[step][1] = data[1][1] - cur[1] == 0 ? 0 : (data[1][1] - cur[1] >0 ? 1 : -1);
			cur[1] += record[step][1];
			step++;
		}
		printf("%d\n", step);
		for (int i = 0; i < step; i++) {
			char *lr = (record[i][0] == 0) ? "\0" : (record[i][0] == 1 ? "R\0" : "L\0");
			char *ud = (record[i][1] == 0) ? "\0" : (record[i][1] == 1 ? "U\0" : "D\0");
			printf("%s%s\n", lr, ud);
		}
	}
	return 0;
}

/*
大佬c++代码

#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	char s[3], t[3];
	while (scanf("%s%s", s, t) != EOF)
	{
		vector<string> ans;
		int dc = t[0] - s[0], dr = t[1] - s[1];
		if (dr < 0)
		{
			if (dc > 0)
			{
				while (dr != 0 && dc != 0)
				{
					ans.push_back("RD");
					dc--, dr++;
				}
			}
			else if (dc < 0)
			{
				while (dr != 0 && dc != 0)
				{
					ans.push_back("LD");
					dc++, dr++;
				}
			}
		}
		else if (dr > 0)
		{
			if (dc > 0)
			{
				while (dr != 0 && dc != 0)
				{
					ans.push_back("RU");
					dc--, dr--;
				}
			}
			else if (dc < 0)
			{
				while (dr != 0 && dc != 0)
				{
					ans.push_back("LU");
					dc++, dr--;
				}
			}
		}
		if (dr != 0)
		{
			if (dr > 0)
			{
				while (dr-- > 0) ans.push_back("U");
			}
			else
			{
				while (dr++ < 0) ans.push_back("D");
			}
		}
		if (dc != 0)
		{
			if (dc > 0)
			{
				while (dc-- > 0) ans.push_back("R");
			}
			else
			{
				while (dc++ < 0) ans.push_back("L");
			}
		}
		cout << ans.size() << endl;
		for_each(ans.begin(), ans.end(), [](string& a) {cout << a << endl; });
	}
	return 0;
}

*/