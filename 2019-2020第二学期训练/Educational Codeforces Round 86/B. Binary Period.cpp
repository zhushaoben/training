#include<bits/stdc++.h>
using namespace std;
char s[105];
void work(){
	scanf("%s",s);bool fl=1;
	for(int i=1;s[i];i++)if(s[i]!=s[i-1])fl=0;
	if(fl){puts(s);return;}
	char pre=s[0];putchar(pre);
	for(int i=1;s[i];i++){
		if(s[i]==pre)putchar(pre^1);
		putchar(pre=s[i]);
	}
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
