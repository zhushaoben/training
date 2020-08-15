#include<bits/stdc++.h>
using namespace std;
char s[20],t[20];
int main(){
	scanf("%s%s",s,t);
	for(int i=0;s[i];i++)if(s[i]!=t[i])return puts("No"),0;
	puts("Yes");
	return 0;
} 
