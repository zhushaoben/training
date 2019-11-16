#include<bits/stdc++.h>
using namespace std;
#define maxn 3000
struct Node{
	int w,v;
	bool operator < (const Node &b)const{
		return w<b.w;
	}
}a[maxn+5];
int n,f[maxn*2+5];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	memset(f,0,sizeof(f));
	for(int i=0;i<n;i++)scanf("%d%d",&a[i].w,&a[i].v);sort(a,a+n);
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=m-1;j>=0;j--){
			f[j+a[i].w]=max(f[j+a[i].w],f[j]+a[i].v);
			ans=max(ans,f[j+a[i].w]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
