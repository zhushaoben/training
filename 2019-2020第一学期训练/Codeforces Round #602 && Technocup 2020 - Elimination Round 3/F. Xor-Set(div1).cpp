#include<bits/stdc++.h>
using namespace std;
#define maxn 100
#define LL long long
struct Node{
	LL l,r;
	bool operator < (const Node &b)const{
		return l!=b.l?l<b.l:r>b.r;
	}
}a[maxn*200],b[maxn*200];
struct Trie{
	int son[2];
	LL size,fi,la;
}t[maxn*maxn*200];
int sia,sib;
void insert(Node a[],int &si,LL l,LL r){
	for(int i=60;~i;i--){
		int k=(x>>i)&1;
		
	}
}
int main(){
	int n,m;LL l,r;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld%lld",&l,&r),insert(a,sia,l,r);
	scanf("%d",&m);
	for(int i=0;i<m;i++)scanf("%lld%lld",&l,&r),insert(b,sib,l,r);
	sort(a,a+sia),sort(b,b+sib);
	for(int i=0;i<sia;i++){
		for(int j=j;j<sib;j++){
			
		}
	}
	return 0;
} 
