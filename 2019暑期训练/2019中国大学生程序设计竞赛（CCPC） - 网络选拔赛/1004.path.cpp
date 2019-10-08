#include<bits/stdc++.h>
using namespace std;
#define maxn 50000
#define fi first
#define se second
#define LL long long
vector<pair<int,int> >v[maxn+5];
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
struct Node{
	LL w;int v;
	bool operator < (const Node &b)const{
		return w>b.w;
	}
}que[maxn*2];
int s,t,n,si,maxk,ans1[maxn];
LL ans[maxn+10];
bool check(LL x){
	s=t=0;
	for(int i=1;i<=n;i++){
		for(auto j:v[i]){
			if(j.fi>x)break;
			que[t++]={j.fi,j.se};
		}
		if(t>=maxk)return 1;
	}
	while(s<t){
		int i=que[s].v;LL w1=que[s].w;s++;
		for(auto j:v[i]){
			if(j.fi+w1>x)break;
			que[t++]={j.fi+w1,j.se};
		}
		if(t>=maxk)return 1;
	}
	return 0;
}
priority_queue<Node,vector<Node> > q;
void work(){
	int m,Q,u,V,w;
	n=read(); m=read(); Q=read();
	for(int i=1;i<=n;i++)v[i].clear();
	for(int i=0;i<m;i++){
		u=read(); V=read(); w=read();
		v[u].push_back(make_pair(w,V));
	}
	for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end());
	maxk=0;
	for(int i=1;i<=Q;i++)ans1[i]=read(),maxk=max(maxk,ans1[i]);
	LL l=0,r=5e13,mid;
	while(l<=r){
		mid=(1ll*l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	for(int i=1;i<=n;i++){
		for(auto j:v[i]){
			if(j.fi>=l)break;
			Node a={j.fi,j.se} ;
			q.push(a);
		}
	}
	si=0;
	while(!q.empty()){
		int i=q.top().v;LL w1=q.top().w;ans[++si]=w1;q.pop();
		for(auto j:v[i]){
			if(j.fi+w1>=l)break;
			q.push(Node{w1+j.fi,j.se});
		}
	}
	for(int i=1;i<=Q;i++){
		printf("%lld\n",(ans1[i]>si?l:ans[ans1[i]]));
	}
}
int main(){
//	freopen("4.in","r",stdin);
//	freopen("4.out","w",stdout); 
	int t=read();
	while(t--)work();
	return 0;
}
