#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
int m,w,f[maxn+5],l[maxn+5],r[maxn+5];
int cal(int x,int n){
	x=(x-1)%n+1; 
	if(x%m==0)return x/m;
	if(n==w)return f[x];
	return cal(n%m+x%m+x/m*(m-1),n-n/m)+n/m;
}
void del(int x){
	r[l[x]]=r[x],l[r[x]]=l[x];
}
void work(){
	int n,q,x;scanf("%d%d%d",&n,&m,&q);m++;
	w=(--n);
	while(w>maxn)w-=w/m;
	for(int i=1;i<=w;i++)l[i]=i-1,r[i]=i+1;r[w]=1,l[1]=w;
	for(int i=1,x=1;i<=w;i++){
		for(int j=(i==1);j<m;j++)x=r[x];
		f[x]=i,del(x);
	}
	for(int i=0;i<q;i++)scanf("%d",&x),printf("%d\n",x==1?1:cal(x-1,n)+1);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
