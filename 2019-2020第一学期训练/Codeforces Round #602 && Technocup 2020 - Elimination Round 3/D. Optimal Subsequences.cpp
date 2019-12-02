#include<bits/stdc++.h>
using namespace std;
#define maxn 200000
struct A{
	int x,id;
	bool operator <(const A &b)const{
		return (x!=b.x)?(x>b.x):(id<b.id);
	}
}b[maxn+5];
struct Q{
	int k,pos,id;
	bool operator < (const Q &b)const{
		return k<b.k;
	}
}q[maxn+5];
int a[maxn+5],ans[maxn+5],si;
struct Trie{
	int size,son[2];
}t[maxn*4];
void add(int x){
	int p=0;
	for(int i=17;~i;i--){
		int k=(x>>i)&1;
		if(!t[p].son[k])t[p].son[k]=++si;
		p=t[p].son[k];t[p].size++;
	}
}
int find(int x){
	int ans=0,p=0;
	for(int i=17;~i;i--){
		int k=(t[t[p].son[0]].size<x);
		if(k)x-=t[t[p].son[0]].size;
		p=t[p].son[k];ans|=(k<<i);
	}
	return ans;
}
int main(){
	int n,m,k,now=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i),b[i]={a[i],i};
	sort(b,b+n);scanf("%d",&m);
	for(int i=0;i<m;i++)scanf("%d%d",&q[i].k,&q[i].pos),q[i].id=i;
	sort(q,q+m);
	for(int i=0;i<m;i++){
		while(now<q[i].k)add(b[now++].id);
		ans[q[i].id]=a[find(q[i].pos)];
	}
	for(int i=0;i<m;i++)printf("%d\n",ans[i]);
	return 0;
}
