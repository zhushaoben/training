#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e3+5;
struct Q{
	int id[N*2],s,t,k;
	LL q[N*2];
	void init(){s=t=0;}
	void insert(LL x,int i){
		while(s<t&&i-id[s]>=k)s++;
		while(s<t&&x<=q[t-1])t--;
		q[t]=x,id[t]=i;t++;
	}
	LL top(){return q[s];}
}q;
int p[N],c[N],st[N*2],top,k;
bool vis[N];LL ans=-1e18;
void solve(){
	LL sum=0,w,w1;int s=top*2;
	for(int i=1;i<=top;i++)st[i+top]=st[i],sum+=c[st[i]];
	if(sum>=0){
		q.init(),q.k=k%top,w=0,w1=k/top;
		q.insert(0,0);
		ans=max(ans,sum*w1);
		if(q.k)for(int i=1;i<=s;i++){
			w+=c[st[i]];
			ans=max(ans,sum*w1+w-q.top());
			q.insert(w,i);
		}
		if(k>=top){
			w1--,q.init(),q.k=top,w=0;
			q.insert(0,0);
			for(int i=1;i<=s;i++){
				w+=c[st[i]];
				ans=max(ans,sum*w1+w-q.top());
				q.insert(w,i);
			}
		}
	}
	q.init(),q.k=k,w=0;
	q.insert(0,0);
	for(int i=1;i<=s;i++){
		w+=c[st[i]];
		ans=max(ans,w-q.top());
		q.insert(w,i);
	}
}
int main(){
	int n,x;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		top=0,x=i;
		do{
			st[++top]=x,vis[x]=1;
			x=p[x];
		}while(x!=i);
		solve();
	}
	printf("%lld\n",ans);
	return 0;
}
