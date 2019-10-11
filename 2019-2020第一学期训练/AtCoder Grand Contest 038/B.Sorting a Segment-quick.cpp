#include<bits/stdc++.h>
using namespace std;
#define maxn 200000
int a[maxn+5],b[maxn+5],c[maxn+5],t1,t2,n,k;
bool vis[maxn+5];
void insert1(int x){
	vis[x]=1;
	while(t1&&b[t1]>x)vis[b[t1]]=0,t1--;
	b[++t1]=x;
}
void insert2(int x){
	while(t2&&a[c[t2]]<a[x])t2--;
	c[++t2]=x;
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i),a[i]++;
	int ans1=n-k+1,mx=0,x;bool fl=0;
	for(int i=1;i<=k;i++)mx=(a[i]>a[i-1]?mx+1:1),insert1(a[i]),insert2(i);
	if(mx>=k)fl=1;
	for(int i=k+1;i<=n;i++){
		insert1(a[i]),insert2(i);
		mx=(a[i]>a[i-1]?mx+1:1);
		if(mx>=k){
			if(fl)ans1--;
			else fl=1;
		}
		else if(vis[a[i-k]]&&(t2<2||c[t2-1]<=i-k))ans1--;
	}
	printf("%d",ans1);
	return 0;
}
