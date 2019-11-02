#include<bits/stdc++.h>
using namespace std;
char s[100005];
int main(){
	int n,ans=1;scanf("%d%s",&n,s);
	for(int i=1;s[i];i++)if(s[i]!=s[i-1])ans++;
	printf("%d",ans);
	return 0;
}
