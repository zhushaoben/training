#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long LL;
int a[N],b[N],vis[N];
int main(){
	int n,x=1,now=0,w,w1;scanf("%d",&n);
	LL k;scanf("%lld",&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	while(!vis[x]){
		b[vis[x]=++now]=x;
		x=a[x];
	}
	w=vis[x]-1,w1=now-w;
	if(k<=w)printf("%d\n",b[k+1]);
	else k-=w,printf("%d\n",b[k%w1+w+1]);
	return 0;
}
