#include<bits/stdc++.h>
using namespace std;
#define maxn 200000
#define LL long long
LL a[maxn+5],b[maxn+5],nex[maxn+5],k;
void work(){
	int n;scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",a+i),a[i]+=a[i-1];
	for(int i=1;i<=n;i++)scanf("%lld",b+i),b[i]+=b[i-1];
	b[n+1]=b[n]+k*2;
	LL w=0;int ans=0,l=0;nex[0]=0;
	for(int i=0;i<n;i++){
		if(a[i]-w>=k){
			nex[l]=i-1,l=i-1,ans++,nex[l]=0;
			w=min(a[i-1],b[i-1]);
			if(a[i]-w>=k)break;
		}
		if(a[i]>b[i]){
			int x=lower_bound(b,b+n+2,k+b[i])-b;
			if(x==n+1)break;
			if(a[x]-b[i]<k){
				printf("%d\n",(i!=0)+ans);
				for(int j=nex[0];j;j=nex[j])printf("%d ",j);if(i)printf("%d",i);puts("");
				return;
			}
		}
		else{
			int x=lower_bound(b,b+n+2,k+a[i])-b;
			if(x==n+1)break;
			if(a[x]-a[i]<k){
				printf("%d\n",(i!=0)+ans);
				for(int j=nex[0];j;j=nex[j])printf("%d ",j);if(i)printf("%d",i);puts("");
				return;
			}
		}
	}
	puts("-1");
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
