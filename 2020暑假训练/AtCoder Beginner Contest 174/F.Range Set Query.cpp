#include<bits/stdc++.h>
using namespace std;
const int N_FENWICK = 5e5,N=5e5+5;
int FENWICK[N_FENWICK+5];//c为树状数组 
inline int lowbit(int x){return x&(-x);}
void add(int x,int num){
	while(x<=N_FENWICK){
		FENWICK[x]+=num;
		x+=lowbit(x);//x+ lowbit(x)为x的父亲节点 
	}
}
int sum(int x){
	int ans=0;
	while(x){
		ans+=FENWICK[x];
		x-=lowbit(x);//c[i]存储i-lowbit[i]+1到i的数组的值，所以求前缀和要不断去掉最后一位 
	}
	return ans;
}
struct Q{
	int l,r,id;
	bool operator < (const Q &b)const {return r<b.r;}
}q[N];
int c[N],pre[N],ans[N];
int main(){
	int n,q1,L=0;scanf("%d%d",&n,&q1);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	for(int i=0;i<q1;i++)scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q,q+q1);
	for(int i=1;i<=n;i++){
		if(pre[c[i]])add(pre[c[i]],-1);
		add(pre[c[i]]=i,1);
		while(L<q1&&q[L].r==i)ans[q[L].id]=sum(i)-sum(q[L].l-1),L++;
	}
	for(int i=0;i<q1;i++)printf("%d\n",ans[i]);
	return 0;
}
