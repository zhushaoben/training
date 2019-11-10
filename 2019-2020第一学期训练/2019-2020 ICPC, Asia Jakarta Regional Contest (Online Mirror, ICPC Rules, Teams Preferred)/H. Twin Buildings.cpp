#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 100000
struct Node{
	int a,b;
	bool operator < (const Node &b)const{
		return a>b.a;
	}
}a[maxn+5];
int main(){
	int n;scanf("%d",&n);LL ans=0;
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i].a,&a[i].b);
		ans=max(ans,1ll*a[i].a*a[i].b);
		if(a[i].a>a[i].b)swap(a[i].a,a[i].b);
	}
	int maxb=0;sort(a,a+n);
	for(int i=0;i<n;i++){
		ans=max(ans,2ll*a[i].a*min(a[i].b,maxb));
		maxb=max(a[i].b,maxb);
	}
	printf("%lld.%d",ans/2,(ans&1)?5:0);
	return 0;
} 
