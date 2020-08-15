#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],T=0;
struct Node{
	long long x,num;
	bool operator < (const Node &b)const{return x>b.x;}
}w[N];
void work(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)scanf("%d",b+i);
	printf("Case #%d: %d ",++T,b[0]);
	long long sum=0,nu=1e9;
	for(int i=0;i<n;i++){
		sum+=a[i],nu=min(1ll*b[i],nu);
		w[i]={sum,nu};
	}
	sort(w,w+n);
	__int128 ans=0,w1=1;int now=0;
	for(int i=0;i<n;i++)
		if(w[i].num>now)ans+=w1*w[i].x*(w[i].num-now),now=w[i].num;
	if(ans>=0)printf("%llu\n",(unsigned long long)ans);
	else printf("-%llu\n",(unsigned long long)-ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
