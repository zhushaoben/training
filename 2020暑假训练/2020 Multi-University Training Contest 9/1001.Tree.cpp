#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int p[N];long long si[N],b[N];
void work(){
	int n;scanf("%d",&n);
	long long ans=0,ma=0;
	si[1]=1;for(int i=2;i<=n;i++)scanf("%d",p+i),si[i]=1;
	for(int i=n;i;i--)si[p[i]]+=si[i],ans+=si[i];
	for(int i=1;i<=n;i++)b[i]=b[p[i]]+n-si[i],ma=max(ma,b[i]);
	printf("%lld\n",ans+ma);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
