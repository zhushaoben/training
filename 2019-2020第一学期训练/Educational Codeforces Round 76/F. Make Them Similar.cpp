#include<bits/stdc++.h>
using namespace std;
#define maxn 100
const int K=15;
struct Trie{
	int son[31];
}t[(1<<(K-1))*maxn+5];
int a[maxn+5],a1[maxn+5],b[maxn+5],cnt[maxn+5],si;
void add(int dep,int x){
	Trie *p=t;
	for(int i=1;i<=dep;i++){
		if(!(p->son[cnt[i]]))p->son[cnt[i]]=++si;
		p=t+(p->son[cnt[i]]);
	}
	p->son[0]=x;
}
int find(int dep){
	Trie *p=t;
	for(int i=1;i<=dep;i++){
		if(!p->son[cnt[i]])return -1;
		p=t+(p->son[cnt[i]]);
	}
	return p->son[0];
}
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)a1[i]=a[i]&((1<<K)-1);
	for(int i=0;i<(1<<(K-1));i++){//if w is answer then ~w is also answer,so we can delete one bit
		for(int j=0;j<n;j++){
			b[j]=a1[j]^i;cnt[j]=0;
			while(b[j])cnt[j]+=(b[j]&1),b[j]>>=1;
		}
		for(int j=n-1;j;j--)cnt[j]-=cnt[j-1]-K;
		add(n-1,i);
	}
	for(int i=0;i<n;i++)a1[i]=(a[i]>>K);
	for(int i=0;i<(1<<K);i++){
		for(int j=0;j<n;j++){
			b[j]=a1[j]^i;cnt[j]=0;
			while(b[j])cnt[j]+=(b[j]&1),b[j]>>=1;
		}
		for(int j=n-1;j;j--)cnt[j]-=cnt[j-1]-K,cnt[j]=30-cnt[j];
		int w;if((w=find(n-1))!=-1)return printf("%d",(i<<K)+w),0;
	}
	puts("-1");
	return 0;
}
