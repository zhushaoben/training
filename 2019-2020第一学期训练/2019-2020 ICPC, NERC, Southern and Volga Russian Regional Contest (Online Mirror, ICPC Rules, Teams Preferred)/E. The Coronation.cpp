#include<bits/stdc++.h>
using namespace std;
#define maxn 50
int st[maxn+5],a[maxn+5][maxn+5];char s[maxn+5][maxn+5];
int sum,rev,n;
void dfs(int x){
	sum++;if(st[x]&4)rev++;
	for(int i=0;i<n;i++){
		if(a[i][x]==0||a[i][x]==6)continue;
		if(st[i])if((st[i]&4)!=((st[x]^a[i][x])&4)){rev=-1;return;}else continue;
		st[i]=st[x]^a[i][x];dfs(i);
		if(rev==-1)return;
	}
}
void dfs1(int x){
	st[x]^=4;
	for(int i=0;i<n;i++){
		if(a[i][x]==0||a[i][x]==6)continue;
		if((st[i]&4)!=((st[x]^a[i][x])&4))dfs1(i);
	}
} 
void work(){
	int m,k;scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int cnt=0;a[i][j]=0;
			for(int k=0;k<m;k++)if(s[i][k]==s[j][k])cnt++;
			if(cnt>=k)a[i][j]|=2;cnt=0;
			for(int k=0;k<m;k++)if(s[i][k]==s[j][m-k-1])cnt++;
			if(cnt>=k)a[i][j]|=4;a[j][i]=a[i][j];
			if(!a[i][j]){puts("-1");return;}
		}
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++)printf("%d ",a[i][j]);
//		puts("");
//	}
	memset(st,0,sizeof(st));int ans=0;
	for(int i=0;i<n;i++){
		if(!st[i]){
			sum=0,rev=0,st[i]=5,dfs(i);
			if(rev==-1){puts("-1");return;}
			if(rev>sum-rev)dfs1(i),ans+=sum-rev;
			else ans+=rev; 
		}
	}
	printf("%d\n",ans);
	for(int i=0;i<n;i++)if(st[i]&4)printf("%d ",i+1);
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
