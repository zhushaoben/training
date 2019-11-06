#include<bits/stdc++.h>
using namespace std;
#define maxn 500
#define maxk 200
struct Node{
	int l,r,c;
	bool operator < (const Node &b)const{
		return r < b.r || r == b.r && l < b.l;
	}
}a[maxn+5];
inline int lowbit(int x){return x&-x;}
int n,c[maxn+5],f[maxn+5],p[maxn+5],sufp[maxn+5],dp[maxn+5];
//S[i] represent which person th i_th person can meet(include himself)()
//p[i] is the smallest x that r[x]>=l[i]
//f[i] is the smallest x that S[x] intersects with S[i] 
//dp[i] is the largest x that only consider first ith person(assume no person behinds them)
struct BIT{
	int a[maxn+5];
	void init(){memset(a,0,sizeof(a));}
	int sum(int x){
		int ans=0;
		while(x)ans+=a[x],x-=lowbit(x);
		return ans;
	}
	void add(int x,int w){
		while(x<=n)a[x]+=w,x+=lowbit(x);
	}
}num[maxk+5];
struct S{
	int a[2],num;bool a0;
	void init(){a0=num=0;}
	void insert(int x){
		if(!x){a0=1;return;}
		if(num)num+=a[0]!=x;
		else a[num++]=x;
	}
}s[maxn+5];
void work(){
	scanf("%d",&n);
	for(int i=0;i<=200;i++)num[i].init();
	for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].c),s[i].init();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j;j--){
			if(a[j].r<a[i].l)break;
			p[i]=j;s[i].insert(a[j].c),s[j].insert(a[i].c);
		}
	}
	int ans=0;sufp[n]=p[n];
	for(int i=n-1;i;i--)sufp[i]=min(sufp[i+1],p[i]);
	for(int i=1;i<=n;i++)f[i]=sufp[p[i]];
	for(int i=1;i<=n;i++){
		if(s[i].a0){
			if(s[i].num>=2)c[i]=-1;
			else if(s[i].num==1)c[i]=s[i].a[0];
			else c[i]=0;
		}
		else{
			c[i]=-1;
			if(s[i].num==1)ans++;
		}
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];if(c[i]==-1)continue;
		num[c[i]].add(f[i],1);
		int l=c[i]?c[i]:1,r=c[i]?c[i]:200;
		for(int j=l;j<=r;j++){
			for(int k=0;k<f[i];k++){
				dp[i]=max(dp[i],dp[k]+num[j].sum(n)-num[j].sum(k)+num[0].sum(n)-num[0].sum(k));
				//assume the person that f[]>k is from j and the others are the best situation of dp[k]
			}
		}
	}
	printf("%d\n",ans+dp[n]);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
