#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 200005
struct Node{
	LL l,r,t;
	bool operator < (const Node &b)const{return t>b.t;}
}a[maxn],x;
priority_queue<Node>q;
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld%lld%lld",&a[i].l,&a[i].r,&a[i].t);
	sort(a,a+n,[&](Node a,Node b){return a.l<b.l;});
	LL cnt=0,r,inf=1e18,w,ans=0,tmp;
	for(int i=0;i<n;i++){
		q.push(a[i]);cnt=a[i].l;
		while(!q.empty()){
			x=q.top();
			if(x.r<=cnt){q.pop();continue;}
			r=min(x.r,(i<n-1)?a[i+1].l:inf);
			w=(r-cnt)/x.t;ans+=w;cnt+=w*x.t;
			if(cnt+x.t>x.r){q.pop();continue;}
			tmp=cnt+x.t;
			while(i<n-1&&a[i+1].l<tmp)
				q.push(a[++i]),tmp=min(tmp,a[i].l+a[i].t);
			ans++;cnt=tmp;
		}
	}
	printf("%lld\n",ans);
	return 0;
} 
