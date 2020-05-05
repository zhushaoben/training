#include<bits/stdc++.h>
using namespace std;
char s[105];
int main(){
	scanf("%s",s);
	int l=strlen(s),n=(l-1)/20+1,m=(l-1)/n+1,w=n*m-l,now=0;
	printf("%d %d\n",n,m);
	for(int i=0;i<n;i++){
		for(int i=1;i<m;i++)putchar(s[now++]);
		if(w)putchar('*'),w--;
		else putchar(s[now++]);
		puts("");
	}
	return 0;
}
