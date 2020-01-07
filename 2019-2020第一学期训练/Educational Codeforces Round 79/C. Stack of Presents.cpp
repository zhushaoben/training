#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int a[maxn],n,N;
int c[maxn];//c为树状数组 
int lowbit(int x){
    return x&(-x);
}
void add(int x,int num){
    while(x<=N){
        c[x]+=num;
        x+=lowbit(x);//x+ lowbit(x)为x的父亲节点 
    }
}
int sum(int x){
    int ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);//c[i]存储i-lowbit[i]+1到i的数组的值，所以求前缀和要不断去掉最后一位 
    }
    return ans;
}
void work(){
	long long ans=0;
	int m,x;scanf("%d%d",&n,&m),N=n;
	memset(c,0,sizeof(int)*(n+5));
	for(int i=0;i<n;i++)scanf("%d",&x),a[x]=i+1;
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		if(sum(n-a[x]+1))continue;
		ans+=(a[x]-i-1)*2;
		add(n-a[x]+1,1);
	}
	printf("%lld\n",ans+m);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
