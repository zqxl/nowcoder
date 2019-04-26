#include <stdio.h>
#include<iostream>
#include <string>
using namespace std;

int main() {
	int m;
	while (~scanf("%d", &m)) {
		string T;
		string data[1000];
		for (int i = 0; i < m; i++) {
			cin>>data[i];
		}
		cin>>T;

		/*此处对data按照字符串长度排序*/
		for (int i = 0; i < m-1; i++) {
			for (int j = 0; j < m-i-1; j++) {
				if (data[j].size() > data[j + 1].size()) {
					string t = data[j];
					data[j] = data[j + 1];
					data[j + 1] = t;
				}
			}
		}

		int res = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < T.size()-data[i].size()+1; j++) {
				string sInT = T.substr(j, data[i].size());
				if (sInT == data[i]) {
					for (int stringI = j; stringI < j + data[i].size(); stringI++) {
						T[stringI] = '0';
					}
					res++;
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}