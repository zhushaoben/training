#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 10000005
int sum[maxn<<2],a[maxn],M;
void build(int n){//建树 
	M=1;while((M<<=1)<n);
	M--;
	for(int i=1;i<=n;i++)sum[i+M]=a[i];
	for(int i=M;i;i--){
		sum[i]=sum[i<<1]+sum[i<<1|1];
	}
}
void change(int x,int y){//单点修改 
	x+=M;
	sum[x]+=y;
	while((x>>=1)){
		sum[x]+=y;
	}
}
int query_node(int x){//单点查询 
	return sum[x+M];
}
int query(int l,int r){//区间查询 
	int ans=0;
	for(l=l+M-1,r=r+M+1;l^r^1;l>>=1,r>>=1){
		if(~l&1)ans+=sum[l^1];
		if(r&1)ans+=sum[r^1];
	}
	return ans;
}
int main(){
	int n,q,l,r,x,k;scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	build(n);
	for(int i=0;i<q;i++){
		scanf("%d",&x);
		if(x==1){
			scanf("%d%*d%d",&l,&k);
			change(l,k);
		}
		else{
			scanf("%d%d",&l,&r);
			printf("%d\n",query(l,r));
		}
	}
	return 0;
} 
