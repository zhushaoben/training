#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;const int N_FENWICK = 3e5+5;
int c[N_FENWICK+5];//c为树状数组 
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
int a[N];
struct Q{
	int x,y,id;
	bool operator < (const Q &b)const{return y<b.y;}
}q[N];
int ans[N];
int main(){
	int n,q1,l=1;scanf("%d%d",&n,&q1);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=q1;i++)scanf("%d%d",&q[i].x,&q[i].y),q[i].y=n-q[i].y,q[i].id=i;
	sort(q+1,q+1+q1);
	for(int i=1;i<=n;i++){
		if(a[i]<=i){
			int l=0,r=i,mid;
			while(l<=r){
				mid=(l+r)>>1;
				if(sum(n+3)-sum(mid)>=i-a[i])l=mid+1;
				else r=mid-1;
			}
			if(l)add(l,1);
		}
		while(q[l].y==i){
			ans[q[l].id]=sum(n+3)-sum(q[l].x+1);
			l++;
		}
	}
	for(int i=1;i<=q1;i++)printf("%d\n",ans[i]);
	return 0;
}
