#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
char s[N];
int main(){
	scanf("%s",s);int l=strlen(s);
	if(s[l-1]=='s')s[l++]='e';
	s[l++]='s';
	puts(s);
	return 0;
} 
