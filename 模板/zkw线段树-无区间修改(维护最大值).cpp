#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 10000005
int ma[maxn<<2],a[maxn],M;
void build(int n){//建树 
	M=1;while((M<<=1)<n);
	M--;
	for(int i=1;i<=n;i++)ma[i+M]=a[i];
	for(int i=M;i;i--){
		ma[i]=max(ma[i<<1],ma[i<<1|1]);
	}
}
void update(int x){//向上更新 
	while((x>>=1)){
		ma[x]=max(ma[x<<1],ma[x<<1|1]);
	}
}
void change_val(int x,int y){//单点修改 
	ma[x+M]=y;
	update(x+M);
}
int query_node(int x){//单点查询 
	return ma[x+M];
}
int query(int l,int r){//区间查询 
	int ans=0;
	for(l=l+M-1,r=r+M+1;l^r^1;l>>=1,r>>=1){
		if(~l&1)ans=max(ma[l^1],ans);
		if(r&1)ans=max(ma[r^1],ans);
	}
	return ans;
}
int main(){
	int n,q,l,r;scanf("%d",&n),n++;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	build(n);
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l+1,r+1));
	}
	return 0;
} 
