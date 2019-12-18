/*
first we split the initial segments to some segments like [a*(2^k),(a+1)*2^k)
then for two segments A[a*(2^k),(a+1)*2^k),B[b*(2^k1),(b+1)*2^k1)(if k>=k1)
the segment C will be[(a^b&(2^60-2^k))*(2^k)]
but the solution runs at O((n*log10^18)^2)
we can optimize it 
*/
#include<bits/stdc++.h>
using namespace std;
#define maxn 100
#define LL long long
#define mo 998244353
LL L,R;
struct Trie{
	int son[maxn*500][2],tot=1;
	bool tag[maxn*500];
	void insert(int &x,LL l=0,LL r=(1ll<<60)-1){
		if(!x)x=++tot;
		if(L<=l&&R>=r){tag[x]=1;return;}
		LL mid=(l+r)>>1;
		if(L<=mid)insert(son[x][0],l,mid);
		if(R>mid)insert(son[x][1],mid+1,r);
	}
}A,B;
int rt=1;const LL inv2=(mo+1)>>1;
struct Node{
	int a,b;
	Node(int x,int y){a=x,b=y;}
}; 
vector<Node> q[61];
LL dfs(int d,LL pre){//calculate the answer of the number in sets that the first 60-d number is equal to pre
	for(auto x:q[d]){
		if(A.tag[x.a]||B.tag[x.b])
		return ((pre<<1)+(1ll<<d)-1)%mo*((1ll<<d)%mo)%mo*inv2%mo; 
	}
	LL res=0;
	for(int x=0;x<2;x++){
		q[d-1].clear();
		for(int y=0;y<2;y++){
			for(auto v:q[d])
			if(A.son[v.a][y]&&B.son[v.b][x^y])q[d-1].emplace_back(A.son[v.a][y],B.son[v.b][x^y]);
		}
		if(!q[d-1].empty())(res+=dfs(d-1,pre|(x*1ll<<(d-1))))%=mo;
	}
	return res;
}
int main(){
	int n,m;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld%lld",&L,&R),A.insert(rt);
	scanf("%d",&m);
	for(int i=0;i<m;i++)scanf("%lld%lld",&L,&R),B.insert(rt);
	q[60].emplace_back(1,1);
	printf("%lld\n",dfs(60,0));
	return 0;
} 
