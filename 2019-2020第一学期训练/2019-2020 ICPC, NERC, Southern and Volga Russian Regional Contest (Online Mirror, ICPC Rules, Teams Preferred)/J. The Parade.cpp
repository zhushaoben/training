#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=30005;
inline ll read()
{
    ll x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll n,k,a[N];
bool check(ll x){
	ll cnt=0,w=0;
	for(int i=1;i<=n;i++){
		ll y=a[i]-w;
		cnt+=y/x;y%=x;
		if(y&&y+a[i+1]>=x)w=x-y,cnt++;
		else w=0;
	}
	return cnt>=k;
}
void work(){
	n=read(); k=read();
	for(int i=1;i<=n;i++) a[i]=read();a[n+1]=0;
	ll l=1,r=2e12,mid,ans=l;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",r*k);
}
int main(){
	int T=read();
	while(T--) work();
	return 0;
}
