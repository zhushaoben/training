#include<bits/stdc++.h>
using namespace std;
#define LL long long 
struct Node{
	LL x,h;
	bool operator <(const Node &b)const{
		if(x!=b.x)return x<b.x;
		return h>b.h;
	}
}a[200005];
LL c[200005];int n;
int lowbit(int x){
    return x&(-x);
}
void add(int x,int num){
    while(x<=n){
        c[x]+=num;
        x+=lowbit(x);
    }
}
LL sum(int x){
    LL ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);//c[i]存储i-lowbit[i]+1到i的数组的值，所以求前缀和要不断去掉最后一位 
    }
    return ans;
}
int main(){
	int d,A;scanf("%d%d%d",&n,&d,&A);
	for(int i=0;i<n;i++)scanf("%d%d",&a[i].x,&a[i].h);
	sort(a,a+n);
	long long ans=0;
	add(1,a[0].h);
	for(int i=2;i<=n;i++){
		add(i,a[i-1].h-a[i-2].h);
	}
	for(int i=1;i<=n;i++){
		long long w=sum(i);
		if(w<=0)continue;
		w=(w-1)/A+1;
		int j=lower_bound(a,a+n,Node{a[i-1].x+2*d,0})-a;
		if(w<=0)continue;
		add(i,-w*A);ans+=w;
		add(j+1,w*A);
	}
	printf("%lld",ans);
	return 0;
} 
