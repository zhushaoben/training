#include<bits/stdc++.h>
using namespace std;
char s[55][55];
void work(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++){
		if(s[i][j]=='1'&&i<n-1&&j<n-1&&s[i+1][j]!='1'&&s[i][j+1]!='1'){puts("NO");return;}
	}
	puts("YES");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
