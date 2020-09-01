#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
#define ull unsigned long long
const int N = 5e6+5, xormod = 10000000;

int n,m,a[N],b[N],s[N*3];
ull k1,k2;
ll f[N*3];

ull xorShift128Plus(){
    ull k3=k1,k4=k2;
    k1=k4;
    k3^=k3<<23;
    k2=k3^k4^(k3>>17)^(k4>>26);
    return k2+k4;
}
void gen(){
    for(int i=1; i<=n; i++) {
    	a[i] = xorShift128Plus() % xormod + 1;
    	b[i] = xorShift128Plus() % xormod + 1;
	}
}

void solve(){
	gen();
	for(int i=1;i<=n;i++)b[i]+=a[i];
	sort(a+1,a+n+1,greater<int>()),sort(b+1,b+n+1,greater<int>());
	a[n+1]=b[n+1]=0;
	f[1]=a[1],s[1]=1;
	if(a[1]+a[2]<b[1])f[2]=b[1],s[2]=0;
	else f[2]=a[1]+a[2],s[2]=2;
	for(int i=3;i<=m;i++){
		if(f[i-1]+a[s[i-1]+1]>f[i-2]+b[(i-2-s[i-2])/2+1])f[i]=f[i-1]+a[s[i-1]+1],s[i]=s[i-1]+1;
		else f[i]=f[i-2]+b[(i-2-s[i-2])/2+1],s[i]=s[i-2];
	}
	ll ans=0;
	for(int i=1;i<=m;i++)ans^=f[i];
	printf("%lld\n",ans);
}
int main(){
	while(scanf("%d%d%llu%llu",&n,&m,&k1,&k2)!=EOF) solve();
	return 0;
}
