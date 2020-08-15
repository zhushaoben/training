#include<bits/stdc++.h>
using namespace std;
#define LL long long
long long randint(LL l,LL r){
	return l+1ll*rand()*rand()*rand()%(r-l+1);
}
const int N=5;
bool vis[N+5];
int a[N+5],b[N+5],as,bs;
void work(){
	memset(vis,0,sizeof(vis));
	int n=randint(2,N),m=randint(1,min(1ll*n*(n-1)/2,N*10ll));
	printf("%d %d\n",n,m);
	for(int i=0;i<n;i++)printf("%d ",randint(1,1e6));
	puts("");
	for(int i=0;i<n;i++)printf("%d ",randint(1,3));
	puts("");
	for(int i=randint(1,n-1);i>=1;i--){
		int x=randint(1,n);
		while(vis[x])x=randint(1,n);
		vis[x]=1;
	}
	as=bs=0;
	for(int i=1;i<=n;i++){
		if(vis[i])a[++as]=i;
		else b[++bs]=i;
	}
	for(int i=0;i<m;i++){
		printf("%d %d\n",a[randint(1,as)],b[randint(1,bs)]);
	}
}
int main(){
	srand(time(NULL));
	int t=randint(1,1);
//	printf("%d\n",t);
	while(t--)work();
	return 0;
}
