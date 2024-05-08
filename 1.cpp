#include <stdio.h>
#include <string.h>

//#include <bits/stdc++.h>
//menggunakan function yang disediakan
//#include <ctype.h>
//int main () {
//	char s[101]={'\0'};
//	scanf("%[^\n]", s);
//	getchar();
//	strrev(s);
//	for (int i=0; i<strlen(s); i++) {
//		if (isupper(s[i])) {
//			s[i]=tolower(s[i]);
//		}
//		else if (islower(s[i])) {
//			s[i]=toupper(s[i]);
//		}
//	}
//	printf("%s\n", s);
//}

//menggunakan ascii dan reverse dengan pengulangan
int main () {
	char s[201]={'\0'};
	printf("Masukan string [max 200 char] : ");
	scanf("%[^\n]", s);
	getchar();
	char temp;
	int len = strlen(s);
	for (int i=0; i<len/2; i++) {
		temp=s[i];
		s[i]=s[len-i-1];
		s[len-i-1]=temp;
	}
	for (int i=0; i<strlen(s); i++) {
		if (s[i]>=65 && s[i]<=90) {
			s[i]+=32;
		}
		else if (s[i]>=97 && s[i]<=122) {
			s[i]-=32;
		}
	}
	printf("%s\n", s);
}
