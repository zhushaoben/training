#include<bits/stdc++.h>
using namespace std;
#define maxn 105
char s[maxn];
int main(){
	scanf("%s",s);int n=strlen(s),ans=0;
	for(int i=0;s[i];i++)if(s[i]!=s[n-i-1])ans++;
	printf("%d",ans/2);
	return 0;
}
