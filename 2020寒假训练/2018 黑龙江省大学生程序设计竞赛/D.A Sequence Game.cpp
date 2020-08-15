/*
���⣺��һ������Ϊn�����У�m��ѯ�ʣ�ÿ���� [ l , r ] ���Ƿ���������һ���������ֵ����Сֵ֮��������ٳ���һ��

˼·������Ĺ�ʽΪ ���ֵ - ��Сֵ + 1 �Ƿ���� ��ͬ���ĸ��� 

           �ж������ڲ�ͬ���ĸ������뵽����ϯ������Ī�ӣ�Ȼ�������С��st���������뵽�ٽ�һ���߶���ά�������С
*/ 
#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
map<int,int>mp;
int a[maxn];
int root[maxn],size,lazy[maxn*70],l[maxn*70],r[maxn*70],ma[maxn*70],Ma[maxn*4],Mi[maxn*4];//�Ƕ�̬������ڵ�Ҫ����n*logn*4 
int modify(int history,int L,int R,int w,int l1,int r1){ 
    int k=++size;
    lazy[k]=lazy[history],ma[k]=ma[history]+w,l[k]=l[history],r[k]=r[history];//��¡�ڵ� 
    if(l1<=L&&r1>=R){//�������䶼Ҫ���޸ģ������Ƿ��� 
        lazy[k]+=w;return k;
    }
    int mid=(L+R)>>1;
    if(l1<=mid)l[k]=modify(l[history],L,mid,w,l1,min(mid,r1));
    if(r1>mid)r[k]=modify(r[history],mid+1,R,w,max(mid+1,l1),r1);
    return k;
}
int query(int x,int pre,int L,int R,int l1,int r1){//ѯ�� 
    if(l1<=L&&r1>=R)return ma[x]-ma[pre];
    int mid=(L+R)>>1;
    int ans=lazy[x],ans1=lazy[pre];//��ǲ����·ţ���Ϊ�ӽڵ�Ҳ�ǹ��õ�,ֻ��ͳ�Ʊ����ɵ�Ӱ�� 
    if(l1<=mid)return ans-ans1+query(l[x],l[pre],L,mid,l1,min(mid,r1));
    return ans-ans1+query(r[x],r[pre],mid+1,R,max(mid+1,l1),r1);
}
void update(int x){
	Ma[x]=max(Ma[x<<1],Ma[x<<1|1]);
	Mi[x]=min(Mi[x<<1],Mi[x<<1|1]);
}
void build(int l,int r,int x){
	if(l==r){
		Ma[x]=Mi[x]=a[l];return;
	}
	int mid=(l+r)>>1;
	build(l,mid,x<<1),build(mid+1,r,x<<1|1);
	update(x);
}
int query_ma(int l,int r,int x,int L,int R){
	if(L<=l&&R>=r)return Ma[x];
	int mid=(l+r)>>1,ans=0;
	if(L<=mid)ans=query_ma(l,mid,x<<1,L,R);
	if(R>mid)ans=max(query_ma(mid+1,r,x<<1|1,L,R),ans);
	return ans;
}
int query_mi(int l,int r,int x,int L,int R){
	if(L<=l&&R>=r)return Mi[x];
	int mid=(l+r)>>1,ans=1e9;
	if(L<=mid)ans=query_mi(l,mid,x<<1,L,R);
	if(R>mid)ans=min(query_mi(mid+1,r,x<<1|1,L,R),ans);
	return ans;
}
void work(){
	int n,m,l,r;scanf("%d%d",&n,&m);
	size=0;mp.clear();
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(mp[a[i]])root[i]=modify(root[i-1],1,n,1,1,mp[a[i]]);
		else root[i]=root[i-1];
		mp[a[i]]=i;
	}
	build(1,n,1);
	for(int i=0;i<m;i++){
		scanf("%d%d",&l,&r);
		int MA=query_ma(1,n,1,l,r),MI=query_mi(1,n,1,l,r),SUM=query(root[r],root[l-1],1,n,l,l);
		if(MA-MI+1==r-l+1-SUM)puts("YES");
		else puts("NO");
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
/*
1
5 3
1 2 2 4 5 
1 5
1 3
3 3
*/
