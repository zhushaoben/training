#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Node{
	int l,r,id;
	bool operator < (const Node &b)const{return l<b.l;}
}a[N],b[N];
priority_queue<pair<int,int> >q;
int ans[N],p[N],mi[N*4],id[N*4];
inline void update(int x){mi[x]=mi[x<<1|(mi[x<<1]>mi[x<<1|1])],id[x]=id[x<<1|(mi[x<<1]>mi[x<<1|1])];}
void build(int l,int r,int x){
	if(l==r){mi[x]=b[p[l]].l,id[x]=l;return;}
	int mid=(l+r)>>1;
	build(l,mid,x<<1);build(mid+1,r,x<<1|1);
	update(x);
}
pair<int,int> query(int x,int l,int r,int L,int R){
	if(L<=l&&R>=r)return {mi[x],id[x]};
	int mid=(l+r)>>1;
	pair<int,int>w1={1e9,0},w2={1e9,0};
	if(L<=mid)w1=query(x<<1,l,mid,L,R);
	if(R>mid)w2=query(x<<1|1,mid+1,r,L,R);
	if(w1.first<w2.first)return w1;
	return w2;
}
int main(){
	int n,l=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",&a[i].l,&a[i].r),a[i].id=i,b[i]=a[i];
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		while(l<n&&a[l].l<=i)q.push({-a[l].r,a[l].id}),l++;
		p[i]=q.top().second;q.pop();
		ans[p[i]]=i;
	}
	build(1,n,1);
	int u=-1,v;
	for(int i=1;i<=n;i++){
		if(b[p[i]].r==i)continue;
		pair<int,int>w=query(1,1,n,i+1,b[p[i]].r);
		if(w.first<=i){u=p[i],v=p[w.second];break;}
	}
	if(u==-1){
		puts("YES");
		for(int i=0;i<n;i++)printf("%d ",ans[i]);
	}
	else{
		puts("NO");
		for(int i=0;i<n;i++)printf("%d ",ans[i]);
		swap(ans[u],ans[v]);puts("");
		for(int i=0;i<n;i++)printf("%d ",ans[i]);
	}
	return 0;
}
