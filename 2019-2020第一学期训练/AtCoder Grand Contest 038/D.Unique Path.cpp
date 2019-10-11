#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
#define LL long long
int fa[maxn+5],a[maxn+5],b[maxn+5],c[maxn+5];
int Find(int x){
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
int main(){
	int n,q,u,v,cnt;LL m;scanf("%d%lld%d",&n,&m,&q),cnt=n;
	for(int i=0;i<n;i++)fa[i]=i;
	bool fl=0;
	for(int i=0;i<q;i++)scanf("%d%d%d",a+i,b+i,c+i),fl|=c[i];
	if(fl&&m==n-1){puts("No");return 0;}
	for(int i=0;i<q;i++){
		if(c[i])continue;
		int x=Find(a[i]),y=Find(b[i]);
		if(x!=y)fa[x]=y,cnt--;
	}
	for(int i=0;i<q;i++){
		if(!c[i])continue;
		int x=Find(a[i]),y=Find(b[i]);
		if(x==y){puts("No");return 0;}
	}
	if(fl&&cnt==2||m>(n-cnt)+1ll*cnt*(cnt-1)/2){puts("No");return 0;}
	puts("Yes");
	return 0;
} 
