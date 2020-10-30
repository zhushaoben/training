#include<bits/stdc++.h>
using namespace std;
char s[10],s1[5];
int main(){
	scanf("%s%s",s,s1);
	if(s[0]=='Y')s1[0]-=32;
	puts(s1);
	return 0;
} 
