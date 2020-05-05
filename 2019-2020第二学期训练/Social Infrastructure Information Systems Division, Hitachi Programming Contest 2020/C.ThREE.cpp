#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int>v[N];
int d[N],num[2];
void dfs(int x,int fa){
	for(auto u:v[x]){
		if(u==fa)continue;
		d[u]=d[x]^1,dfs(u,x);
	}
	num[d[x]]++;
}
int main(){
	int n,x,y;scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	dfs(1,0);
	int a=1,b=2,c=3;
	if(num[0]<=n/3){
		for(int i=1;i<=n;i++){
			if(d[i]%2==0)printf("%d ",c),c+=3;
			else printf("%d ",a<=n?(a+=3)-3:(b<=n?(b+=3)-3:(c+=3)-3));
		}
		return 0;
	}
	if(num[1]<=n/3){
		for(int i=1;i<=n;i++){
			if(d[i]&1)printf("%d ",c),c+=3;
			else printf("%d ",a<=n?(a+=3)-3:(b<=n?(b+=3)-3:(c+=3)-3));
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(d[i]&1)printf("%d ",a<=n?(a+=3)-3:(c+=3)-3);
		else printf("%d ",b<=n?(b+=3)-3:(c+=3)-3);
	}
	return 0;
}
