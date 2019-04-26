#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct APai {
	// 1-5�ֱ��ʾ�Ƶ�������6��ʾ����
	int type;
	// ÿ���Ƶ���ֵ��С
	int pais[5];
	// �Ƶĸ���
	int num;
}Pai;

int strFindLine(char *s) {
	for (int i = 0; s[i]!='\0'; i++) {
		if (s[i] == '-')
			return i;
	}
	return -1;
}
// ����2-14������Ϊ66
int str2num(char *s) {
	if (strlen(s) == 2)
		return 10;
	if (strlen(s) == 5)
		return 66;

	// һ���ַ������
	if (s[0] < '9')
		return (int)(s[0] - '0');
	if (s[0] == 'A')
		return 14;
	return s[0] - 'J' + 11;
}

Pai str2pai(char *s) {
	Pai p = {0};
	int sl = strlen(s);
	int c=0;
	char st[10] = {};
	for (int i = 0; i < sl; i++) {
		if (s[i] == ' ') {
			strncpy(st, s + c, i - c);
			p.pais[p.num++] = str2num(st);
			c = i + 1;
		}
		else if(i == sl - 1){
			strncpy(st, s + c, i - c + 1);
			p.pais[p.num++] = str2num(st);
			c = i + 1;
		}
	}
	
	if (p.pais[0] == 66)
		p.type = 6;
	else
		p.type = p.num;
	return p;
}

int main() {
	char s[40];
	char p1[20];
	char p2[20];
	while (~scanf("%[^\n]", s)) {
		int t = strFindLine(s);
		s[t] = '\0';
		strcpy(p1, s);
		strcpy(p2, s + t + 1);

		// �ֱ����ṹ��
		Pai pai1 = str2pai(p1);
		Pai pai2 = str2pai(p2);

		// �ų���ը���
		if (pai1.type == 6 || pai2.type == 6) {
			printf("joker JOKER\n");
			return 0;
		}
		// �ų�˫ը�����
		if (pai1.type == 4 && pai2.type==4) {
			if (pai1.pais[0] > pai2.pais[0]) {
				printf("%s", p1);
				return 0;
			}
			else {
				printf("%s\n", p2);
				return 0;
			}
		}

		// �ų���ը��
		if (pai1.type == 4) {
			printf("%s\n", p1);
			return 0;
		}
		else if (pai2.type == 4) {
			printf("%s\n", p2);
			return 0;
		}

		// error���
		if (pai1.type != pai2.type)
		{
			printf("ERROR\n");
			return 0;
		}

		if (pai1.pais[0] > pai2.pais[0]) {
			printf("%s", p1);
			return 0;
		}
		else {
			printf("%s\n", p2);
			return 0;
		}

	}
	return 0;
}