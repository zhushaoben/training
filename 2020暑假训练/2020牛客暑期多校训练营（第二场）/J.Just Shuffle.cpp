#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,S=1e4;
typedef long long ll;
void exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){x=1,y=0;return;}
    ll t;
    exgcd(b,a%b,x,y);
    t=x,x=y,y=t-(a/b)*y;
}
int st[N],top,k,w[N],w1[N];
struct A{
	int a[N],l;
	void Scan(){for(int i=1;i<=l;i++)scanf("%d",a+i);}
	void Print(){for(int i=1;i<=l;i++)printf("%d ",a[i]);}
	void operator *=(const A &b){
		for(int i=0;i<top;i++)w[st[i]]=a[st[i]],w1[st[i]]=b.a[st[i]];
		for(int i=0;i<top;i++)a[st[i]]=w1[w[st[i]]];
	}
}x,ans;
bool vis[N];
void power(int b){
	while(b){
		if(b&1)ans*=x;
		x*=x,b>>=1;
	}
}
int main(){
	scanf("%d%d",&x.l,&k);
	x.Scan();ans.l=x.l;
	for(int i=1;i<=x.l;i++)ans.a[i]=i;
	for(int i=1;i<=x.l;i++){
		if(vis[i])continue;
		ll a,b;int u=x.a[i],w=0;top=0;
		do{
			st[top++]=u,vis[u]=1,w++;
			u=x.a[u];
		}while(!vis[u]);
		exgcd(w,k,a,b);
		power((b%w+w)%w);
	}
	ans.Print();
	return 0;
}
