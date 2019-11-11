#include<bits/stdc++.h>
using namespace std;
#define maxn 200000
#define LL long long
struct Node{
	int x,id;
	bool operator < (const Node &b)const{
		return x<b.x;
	}
}a[maxn+5];
int ans[maxn+5],pre,la[maxn+5],num[maxn+5];LL f[maxn+5],sum;
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i),a[i].id=i;
	sort(a,a+n);
	for(int i=1;i<n;i++)sum+=a[i].x-a[i-1].x;
	for(int i=3;i<=n-3;i++){f[i]=f[pre]+a[i].x-a[i-1].x,num[i]=num[pre]+1;la[i]=pre;if(f[i-2]>f[pre])pre=i-2;}
	for(int i=n-2;i<n;i++)if(f[i-2]>f[pre])pre=i-2;
	printf("%lld %d\n",sum-f[pre],num[pre]+1);
	int x=1;for(int i=n-1;~i;i--){ans[a[i].id]=x;if(i==pre)x++,pre=la[pre];}
	for(int i=0;i<n;i++)printf("%d ",ans[i]);
	return 0;
}
