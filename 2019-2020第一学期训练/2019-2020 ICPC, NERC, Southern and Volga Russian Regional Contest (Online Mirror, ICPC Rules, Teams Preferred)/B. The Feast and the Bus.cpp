#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=8005;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[N],ma;ll ans;
int main()
{
	int n=read(),k=read(),x,k1=k/2;
	for(int i=0;i<n;i++)x=read(),a[x]++;
	sort(a+1,a+k+1);ma=a[k];ans=1ll*ma*k;
	for(int i=1;i<=k1;i++,k--){
		for(int j=1;j<=i;j++){
			ma=max(ma,a[j]+a[i*2+1-j]);
		}
		ans=min(ans,1ll*ma*(k-1));
	}
	printf("%lld\n",ans);
	return 0;
}
