#include<bits/stdc++.h>
using namespace std;
char s[20];
int main(){
	scanf("%s",s);
	for(int i=0;s[i];i++)if(s[i]<'a')s[i]+='a'-'A';
	if(s[0]=='l'&&s[1]=='o'&&s[2]=='v'&&s[3]=='e'&&s[4]=='l'&&s[5]=='y')puts("lovely");
	else puts("ugly");
	return 0;
} 
