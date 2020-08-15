#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5;
LL ma[N*4];
void change(int L,int R,int x,int l,LL w){
	if(L==R){ma[x]=w;return;}
	int mid=(L+R)>>1;
	if(mid>=l)change(L,mid,x<<1,l,w);
	else change(mid+1,R,x<<1|1,l,w);
	ma[x]=max(ma[x],w);
} 
long long query(int L,int R,int x,int l,int r){
	if(L>=l&&R<=r){return ma[x];}
	int mid=(L+R)>>1;
	long long ans=0;
	if(mid>=l)ans=max(ans,query(L,mid,x<<1,l,r));
	if(mid<r)ans=max(ans,query(mid+1,R,x<<1|1,l,r));
	return ans;
}
int a[N],b[N];
LL f[N];
void work(){
	int n,d;scanf("%d%d",&n,&d);
	for(int i=0;i<n;i++)scanf("%d%d",a+i,b+i);
	for(int i=0;i<n;i++){
		int l=max(1,a[i]-d),r=min(100000,a[i]+d);
		f[i]=query(1,100000,1,l,r)+b[i];
		change(1,100000,1,a[i],f[i]);
	}
	printf("%lld",ma[1]);
}
int main(){
	int t=1;
//	scanf("%d",&t);
	while(t--)work();
	return 0;
} 
