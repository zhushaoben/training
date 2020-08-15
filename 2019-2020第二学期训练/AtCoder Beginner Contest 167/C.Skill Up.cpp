#include<bits/stdc++.h>
using namespace std;
const int N=12;
int c[N],a[N][N],ans=1e9,w,now[N],n,m,x;
bool check(){
	for(int i=0;i<m;i++)if(now[i]<x)return 0;
	return 1;
}
void dfs(int d){
	if(check()){ans=min(w,ans);return;}
	if(d==n||w>=ans)return;
	w+=c[d];for(int i=0;i<m;i++)now[i]+=a[d][i];
	dfs(d+1);
	w-=c[d];for(int i=0;i<m;i++)now[i]-=a[d][i];
	dfs(d+1);
}
int main(){
	scanf("%d%d%d",&n,&m,&x);
	for(int i=0;i<n;i++){
		scanf("%d",c+i);
		for(int j=0;j<m;j++)scanf("%d",a[i]+j);
	}
	dfs(0);
	printf("%d",ans==1e9?-1:ans);
	return 0;
}
