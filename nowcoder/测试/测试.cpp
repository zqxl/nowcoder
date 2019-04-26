#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>

int dis(int x) {
	return x+1;
}

int main() {
	int (*f)(int);
	f = dis;
	int x = f(2);
	getchar();
	return 0;
}

/*
请登录京东在线考试官方指定平台：【赛码 在线考试系统】
登录路径：https://jd.acmcoder.com/cand/login
登录帐号：jd
登录密码：3rtavg
*/