#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 1<<17
#define inf 0x3fffffff
int mi[maxn],M,s,a[maxn];
void build(int n){//建树 
	M=1;
	while((M<<=1)<n);
	M--;
	for(int i=0;i<n;i++){
		mi[i+M]=a[i];
	}
	for(int i=M;i;i--){
		mi[i]=min(mi[i<<1],mi[i<<1|1]);
		mi[i<<1]-=mi[i],mi[i<<1|1]-=mi[i];//节点存储与父节点的差值 
	}
}
void change(int x,int w){//单点修改 
	x+=M;mi[x]+=w;
	int tmp;
	while(x>>=1){//更新祖先的值 
		tmp=min(mi[x<<1],mi[x<<1|1]);
		mi[x]+=tmp,mi[x<<1]-=tmp,mi[x<<1|1]-=tmp;
	}
}
void modify(int l,int r,int w){//区间修改
	int tmp;
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
		if(~l&1)mi[l^1]+=w;//如果为左端为左子节点，则右子节点一定被包含,更新值 
		if(r&1)mi[r^1]+=w;//如果为右端为右子节点同理 
		tmp=min(mi[l],mi[l^1]),mi[l]-=tmp,mi[l^1]-=tmp,mi[l>>1]+=tmp;//更新左右端父节点的值 
		tmp=min(mi[r],mi[r^1]),mi[r]-=tmp,mi[r^1]-=tmp,mi[r>>1]+=tmp; 
	}
	while(l>>=1){//更新到根的路径的值 
		tmp=min(mi[l<<1],mi[l<<1|1]),mi[l<<1]-=tmp,mi[l<<1|1]-=tmp,mi[l]+=tmp;
	}
}
int query_node(int x){//单点查询 
	x+=M;
	int ans=mi[x];
	while(x>>=1)ans+=mi[x];//因为存的为与父节点的差，所以答案要加上所有路径上的点的值 
	return ans;
}
int query(int l,int r){//区间查询 
	if(l==r)return query_node(l);//特判单点查询，否则会死循环 
	int ans,L=0,R=0;
	for(l+=M,r+=M;l^r^1;l>>=1,r>>=1){
		L+=mi[l],R+=mi[r];//L,R表示左右端点所在节点表示的区间与所求区间交集的最小值 
		if(~l&1)L=min(L,mi[l^1]);//如果为左端为左子节点，则右子节点一定被包含,更新值
		if(r&1)R=min(R,mi[r^1]);//如果为右端为右子节点同理
	}
	L+=mi[l],R+=mi[r],ans=min(L,R);//答案要加上路径上所有的点的值
	while(l>>=1){
		ans+=mi[l];
	}
	return ans;
}
int main(){
	int n,m,l,r,w,x;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	build(n);
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		if(x==1){
			scanf("%d%d%d",&l,&r,&w);
			modify(l,r,w);
		}
		else{
			scanf("%d%d",&l,&r);
			printf("%d\n",query(l,r));
		}
	}
	return 0;
} 
