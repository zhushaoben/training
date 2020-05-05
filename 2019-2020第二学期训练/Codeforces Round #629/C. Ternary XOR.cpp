#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
char s[N];
void work(){
	int n;scanf("%d%s",&n,s);
	bool fl=0;
	for(int i=0;i<n;i++){
		if(fl)putchar('0');
		else if(s[i]=='2')putchar('1');
		else if(s[i]=='0')putchar('0');
		else putchar('1'),fl=1;
	}
	fl=0;puts("");
	for(int i=0;i<n;i++){
		if(fl)putchar(s[i]);
		else if(s[i]=='2')putchar('1');
		else if(s[i]=='0')putchar('0');
		else putchar('0'),fl=1;
	}
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
