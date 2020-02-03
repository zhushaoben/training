#include<bits/stdc++.h>
using namespace std;
#define maxn 5005
#define mo 998244353
#define LL long long
struct Node{
	int l,r;
	bool operator < (const Node &b)const{
		return l+r<b.l+b.r;
	}
}a[maxn];
LL Pow(LL a,int b){
	LL ans=1;
	while(b){
		if(b&1)(ans*=a)%=mo;
		(a*=a)%=mo,b>>=1;
	}
	return ans;
}
int inv[maxn];
LL sum(int l,int r){
	return 1ll*(l+r)*(r-l+1)/2%mo;
}
int calc(int i,int j){
	if(a[j].l>a[i].r)return 1;
	if(a[i].l>=a[j].r)return 0;
	int s=max(0,a[j].l-a[i].l);
	return (1ll*s*(a[j].r-a[j].l+1)%mo+sum(max(0,a[j].r-a[i].r),max(0,a[j].r-a[i].l-s)))*inv[i]%mo*inv[j]%mo;
}
int main(){
	int n,ans=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",&a[i].l,&a[i].r);
	sort(a,a+n);
	for(int i=0;i<n;i++)inv[i]=Pow(a[i].r-a[i].l+1,mo-2);
	for(int i=0;i<n;i++)
	for(int j=0;j<i;j++)
	(ans+=calc(i,j))%=mo;
	printf("%d",ans);
	return 0;
} 
