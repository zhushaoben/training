#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
char s[maxn],s1[maxn];
int ma[maxn*4],mi[maxn*4],lazy[maxn*4],k;
void pushdown(int x){//标记下放 
	lazy[x<<1]+=lazy[x],lazy[x<<1|1]+=lazy[x],
	ma[x<<1]+=lazy[x],ma[x<<1|1]+=lazy[x],mi[x<<1]+=lazy[x],mi[x<<1|1]+=lazy[x],lazy[x]=0;
}
void update(int x){
	ma[x]=max(ma[x<<1],ma[x<<1|1]),mi[x]=min(mi[x<<1],mi[x<<1|1]);
}
int L,R,w;
void modify(int l,int r,int x){//区间修改 
	if(L<=l&&R>=r){lazy[x]+=w,ma[x]+=w,mi[x]+=w;return;}
	int mid=(l+r)>>1;
	if(lazy[x])pushdown(x);
	if(mid>=L)modify(l,mid,x<<1);
	if(mid<R)modify(mid+1,r,x<<1|1);
	update(x);
}
int query(int l,int r,int x){
	if(l==r)return mi[x];
	int mid=(l+r)>>1;pushdown(x);
	return query(mid+1,r,x<<1|1);
}
void work(){
	int n,now=1;scanf("%d%s",&n,s);
	for(int i=0;i<n;i++){
		if(s[i]=='L')now--,now=max(1,now);
		else if(s[i]=='R')now++;
		else{
			if(s1[now]=='(')L=now,R=n,w=-1,modify(1,n,1);
			if(s1[now]==')')L=now,R=n,w=1,modify(1,n,1);
			if(s[i]=='(')L=now,R=n,w=1,modify(1,n,1);
			else if(s[i]==')')L=now,R=n,w=-1,modify(1,n,1);
			s1[now]=s[i];
		}
		if(mi[1]>=0&&query(1,n,1)==0)printf("%d ",ma[1]);
		else printf("-1 ");
	}
}
int main(){
	int t=1;//scanf("%d",&t);
	while(t--)work();
	return 0;
} 
