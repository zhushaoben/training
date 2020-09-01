#include<bits/stdc++.h>
using namespace std;
char s[1005],t[1005];
int main(){
	scanf("%s%s",s,t);
	int ans=1e5,l1=strlen(s),l2=strlen(t);
	for(int i=0;i<=l1-l2;i++){
		int w=0;
		for(int j=0;t[j];j++)w+=(s[i+j]!=t[j]);
		ans=min(ans,w);
	}
	printf("%d",ans);
	return 0;
}
