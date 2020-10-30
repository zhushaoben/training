#include<bits/stdc++.h>
using namespace std;
char s[10],ans[10];
void work(){
	int x,fl=0,x1;scanf("%s",s);
	if(s[0]=='-')fl=1;
	sscanf(s+1,"%d",&x);
	int8_t w;
	putchar(fl|0x30);
	for(int i=6;~i;i--)putchar(((x>>i)&1)|0x30);puts("");
	putchar(fl|0x30);
	for(int i=6;~i;i--)putchar(((x>>i)&1)^0x31);puts("");
	if(fl)x=-x;
	for(int i=7;~i;i--)putchar(((x>>i)&1)|0x30);puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
