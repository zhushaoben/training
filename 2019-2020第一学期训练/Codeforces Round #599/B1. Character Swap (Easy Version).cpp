#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
char s[maxn+5],t[maxn+5];
int a[2],num;
int work(){
	int n;scanf("%d%s%s",&n,s,t);
	num=0;for(int i=0;s[i];i++){if(s[i]!=t[i])if(num<2)a[num++]=i;else return puts("NO"),0;}
	if((num==2&&s[a[0]]==s[a[1]]&&t[a[0]]==t[a[1]])||!num)return puts("YES"),0;
	return puts("NO"),0;
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
