#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=5e5;
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
struct Node{
	vector<int>v;
	LL c;int l;
	bool operator < (const Node &b)const{
		if(l!=b.l)return l<b.l;
		for(int i=0;i<l;i++)if(v[i]!=b.v[i])return v[i]<b.v[i]; 
	}
	bool operator == (const Node &b)const{
		if(l!=b.l)return 0;
		for(int i=0;i<l;i++)if(v[i]!=b.v[i])return 0; 
		return 1;
	}
}a[N];
void work(){
	int n,m,u,v;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i].c);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		a[v].v.push_back(u),a[v].l++;
	}
	for(int i=1;i<=n;i++)sort(a[i].v.begin(),a[i].v.end());
	sort(a+1,a+n+1);
	LL ans=0,w=0;
	for(int i=1;i<=n;i++){
		w+=a[i].c;if(a[i].l==0)w-=a[i].c;
		if(a[i]==a[i+1])continue;
		else ans=gcd(ans,w),w=0;
	}
	for(int i=1;i<=n;i++)a[i].v.clear(),a[i].l=0;
	printf("%lld\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
