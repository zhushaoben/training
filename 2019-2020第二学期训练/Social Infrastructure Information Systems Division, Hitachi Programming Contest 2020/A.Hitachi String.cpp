#include<bits/stdc++.h>
using namespace std;
char s[20];
int main(){
	scanf("%s",s);int l=strlen(s);
	if(l&1)return puts("No"),0;
	for(int i=0;s[i];i++){
		if(i&1&&s[i]!='i')return puts("No"),0;
		if(i%2==0&&s[i]!='h')return puts("No"),0;
	}
	puts("Yes");
	return 0;
} 
