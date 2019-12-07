#include<bits/stdc++.h>
using namespace std;
#define maxn 300005
char s[maxn];
int main(){
	scanf("%s",s);int r=strlen(s)-1,l=0,w;char x;
	while(l<=r){
		if(s[l]!=s[r])return puts("0"),0;
		w=0,x=s[l];while(l<=r&&s[l]==x)l++,w++;
		while(r>=l&&s[r]==x)r--,w++;
		if(w<2||(w<3&&l<=r))return puts("0"),0;
	}
	printf("%d\n",w+1);
	return 0;
}
