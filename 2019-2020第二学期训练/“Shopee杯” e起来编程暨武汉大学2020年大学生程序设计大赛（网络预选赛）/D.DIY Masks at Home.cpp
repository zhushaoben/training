#include<bits/stdc++.h>
using namespace std;
const int N=2005;
char s[N][N];
int up[N][N],n,m;
bool check(int x){
	for(int i=1;i<=n;i++){
		int l=0;
		for(int j=1;j<=m;j++){
			if(s[i][j]!=s[i][l])l=j;
			if(up[i][j]<x)l=j+1;
			if(j-l+1>=x)return 1;
		}
	}
	return 0;
}
void work(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)if(s[i][j]==s[i-1][j])up[i][j]=up[i-1][j]+1;
		else up[i][j]=1;
	}
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",r);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
