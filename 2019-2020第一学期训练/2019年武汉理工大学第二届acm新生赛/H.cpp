#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
#define LL long long
struct Node{
	int u,v;
	bool operator < (const Node &b)const{
		return u<b.u;
	}
}a[maxn+5];
void work(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d%d",a+i,&a[i].v);
	sort(a,a+n);
	LL sum=0,ans=1e17;
	for(int i=0;i<m;i++)sum+=a[i].u;
	for(int i=0;i<m;i++)ans=min(ans,sum*2-a[i].u-a[i].v);
	sum-=a[m-1].u;
	for(int i=m;i<n;i++)ans=min(ans,sum*2+a[i].u-a[i].v);
	printf("%lld\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
