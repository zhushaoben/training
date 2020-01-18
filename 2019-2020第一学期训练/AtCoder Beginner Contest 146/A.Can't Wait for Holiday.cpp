#include <bits/stdc++.h>
using namespace std;
char s[10];
int main(){
	int now=0;scanf("%s",s);
	if(s[0] == 'S') {
		if(s[1] == 'U') now = 0;
		else now = 6;
	}
	if(s[0] == 'M') now = 1;
	if(s[0] == 'T') {
		if(s[1] == 'U') now = 2;
		else now = 4;
	}
	if(s[0] == 'W') now = 3;
	if(s[0] == 'F') now = 5;
	printf("%d\n", 7 - now);
	return 0;
} 
