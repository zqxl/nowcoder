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
���¼�������߿��Թٷ�ָ��ƽ̨�������� ���߿���ϵͳ��
��¼·����https://jd.acmcoder.com/cand/login
��¼�ʺţ�jd
��¼���룺3rtavg
*/