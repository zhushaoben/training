#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=100003;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0',ch=getchar();}
    return x*f;
}
int t,a,c,m;
bool check(int x,int len)
{
	for(int i=1; i<=len; i++) {
		x=(1ll*a*x+c)%m;
	}
	return x%2==0;
}
void solve()
{
	t=read(); a=read(); c=read(); m=read();
	ll cnt=0,sum=1ll*(t+1)*(t+1);
	for(int i=0; i<=t; i++) {
		for(int j=0; j<=t; j++) {
			if(check(i+j, abs(i-j))) cnt++;
		}
	}
	ll g=__gcd(cnt, sum);
	printf("%lld/%lld\n",cnt/g,sum/g);
}
int main()
{
	int T=read();
	while(T--) solve();
}
