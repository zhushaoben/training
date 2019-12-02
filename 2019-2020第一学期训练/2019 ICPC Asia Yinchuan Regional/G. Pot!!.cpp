#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
int ma[4][maxn*4],lazy[4][maxn*4],L,R,w,a[]={2,3,5,7};
char op[20];
void pushdown(int x){
	for(int i=0;i<4;i++)
		if(lazy[i][x])
			lazy[i][x<<1]+=lazy[i][x],lazy[i][x<<1|1]+=lazy[i][x],
			ma[i][x<<1]+=lazy[i][x],ma[i][x<<1|1]+=lazy[i][x],lazy[i][x]=0;
}
void update(int x){
	for(int i=0;i<4;i++)ma[i][x]=max(ma[i][x<<1],ma[i][x<<1|1]);
}
void modify(int l,int r,int x){
	if(L<=l&&R>=r){
		int w1=w;
		for(int i=0;i<4;i++){
			while(w1%a[i]==0)ma[i][x]++,lazy[i][x]++,w1/=a[i];
		}
		return;
	}
	pushdown(x);
	int mid=(l+r)>>1;
	if(L<=mid)modify(l,mid,x<<1);
	if(R>mid)modify(mid+1,r,x<<1|1);
	update(x);
}
int query(int l,int r,int x){
	if(L<=l&&R>=r){
		int ans=0;
		for(int i=0;i<4;i++)ans=max(ans,ma[i][x]);
		return ans;
	}
	pushdown(x);
	int mid=(l+r)>>1,ans=0;
	if(L<=mid)ans=max(ans,query(l,mid,x<<1));
	if(R>mid)ans=max(ans,query(mid+1,r,x<<1|1));
	return ans;
}
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%s",op);
		if(op[1]=='U'){
			scanf("%d%d%d",&L,&R,&w);
			modify(1,n,1);
		}
		else{
			scanf("%d%d",&L,&R);
			printf("ANSWER %d\n",query(1,n,1));
		}
	}
	return 0;
}
