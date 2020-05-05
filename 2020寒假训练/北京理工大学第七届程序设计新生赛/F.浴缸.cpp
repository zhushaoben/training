#include<bits/stdc++.h>
using namespace std;
int num[105];
int main(){
	int n,m,v,x;scanf("%d%d%d",&n,&m,&v);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&x),num[x]++;
	for(int i=100;i;i--)num[i]+=num[i+1];
	int ans=100;
	for(;ans;ans--){
		if(!v)break;
		v-=num[ans];
	}
	printf("%d",ans);
	return 0;
}
