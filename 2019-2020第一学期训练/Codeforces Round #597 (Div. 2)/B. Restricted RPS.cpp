#include<bits/stdc++.h>
using namespace std;
char s[200];
void work(){
	int n,a,b,c,a1=0,b1=0,c1=0;scanf("%d%d%d%d%s",&n,&a,&b,&c,s);
	for(int i=0;i<n;i++){
		if(s[i]=='R')a1++;
		else if(s[i]=='P')b1++;
		else c1++;
	}
	if((min(b,a1)+min(c,b1)+min(a,c1))>=(n+1)/2)puts("YES");
	else {puts("NO");return;}
	for(int i=0;i<n;i++){
		if(s[i]=='R'){a1--;if(b)b--,putchar('P');else if(c-b1>0)c--,putchar('S');else a--,putchar('R');}
		else if(s[i]=='P'){b1--;if(c)c--,putchar('S');else if(a-c1>0)a--,putchar('R');else b--,putchar('P');}
		else {c1--;if(a)a--,putchar('R');else if(b-a1>0)b--,putchar('P');else c--,putchar('S');}
	}
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
