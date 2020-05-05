#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char s[N];
void work(){
	int n,k;scanf("%d%d%s",&n,&k,s);
	sort(s,s+n);
	if(s[0]!=s[k-1]){printf("%c\n",s[k-1]);return;}
	if(s[k]==s[n-1]){
		putchar(s[0]);
		for(int i=(n-1)/k;i;i--)putchar(s[n-1]);
		puts("");return;
	}
	puts(s+k-1);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
