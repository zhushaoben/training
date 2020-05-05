#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],si,vis[N],t;
void work(){
	int n,k,x;scanf("%d%d",&n,&k);si=0;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(vis[x]!=t)vis[x]=t,a[si++]=x;
	}
	if(si>k){puts("-1");return;}
	printf("%d\n",k*n);
	for(int i=0;i<n;i++)for(int j=0;j<k;j++)printf("%d ",a[j%si]);
	puts("");
}
int main(){
	int T;scanf("%d",&T);
	for(t=1;t<=T;t++)work();
	return 0;
}
