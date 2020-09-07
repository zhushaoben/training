#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,N_FENWICK=3e5+5;
int c[N_FENWICK];//c为树状数组 
inline int lowbit(int x){return x&(-x);}
void add(int x,int num){
	while(x<=N_FENWICK){
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
int query(int x){
	int w=0,ans=0;
	for(int i=1<<18;i;i>>=1){if(ans+i<=N_FENWICK&&w+c[ans+i]<=x)w+=c[ans+=i];}
	return ans;
}
int a[N];
struct Q{
	int x,y,id;
	bool operator < (const Q &b)const{return y<b.y;}
}q[N];
int ans[N];
int main(){
	int n,q1,l=1,sum1=0;scanf("%d%d",&n,&q1);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=q1;i++)scanf("%d%d",&q[i].x,&q[i].y),q[i].y=n-q[i].y,q[i].id=i;
	sort(q+1,q+1+q1);
	for(int i=1;i<=n;i++){
		if(a[i]<=i){
			int l=query(sum1+a[i]-i);
			if(l)add(min(l+1,i+1),1),sum1++;
		}
		while(q[l].y==i)ans[q[l].id]=sum1-sum(q[l].x+1),l++;
	}
	for(int i=1;i<=q1;i++)printf("%d\n",ans[i]);
	return 0;
}
