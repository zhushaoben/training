#include<bits/stdc++.h>
using namespace std;
char s[100005];
void work(){
	int u=0,d=0,l=0,r=0;scanf("%s",s);
	for(int i=0;s[i];i++){
		switch(s[i]){
			case 'U' : u++;break;
			case 'D' : d++;break;
			case 'L' : l++;break;
			default:r++;
		}
	}
	u=min(u,d),l=min(l,r);
	if(!u)l=min(1,l);if(!l)u=min(1,u);
	printf("%d\n",(u+l)<<1);
	for(int i=0;i<l;i++)putchar('L');
	for(int i=0;i<u;i++)putchar('U');
	for(int i=0;i<l;i++)putchar('R');
	for(int i=0;i<u;i++)putchar('D');
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
