#include<bits/stdc++.h>
char s[105][105];
int main(){
	int ans=0,h,w;scanf("%d%d",&h,&w);
	for(int i=0;i<h;i++)scanf("%s",s[i]);
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			if(s[i][j]=='.')ans+=(s[i][j+1]=='.')+(s[i+1][j]=='.');
	printf("%d",ans);
	return 0;
}
