#include<bits/stdc++.h>
using namespace std;
int main(){
	char s[5];scanf("%s",s);
	int w=0,ans=0;
	for(int i=0;s[i];i++){
		if(s[i]=='R')w++;
		else w=0;
		ans=max(ans,w);
	}
	printf("%d",ans);
	return 0;
}
