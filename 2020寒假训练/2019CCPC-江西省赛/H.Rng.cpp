#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 1000005
#define mo 1000000007
LL inv[maxn],s[maxn];int n;
void work(){
	LL ans=0,w=0;
	for(int i=1;i<=n;i++){
		(w+=s[i]+mo-s[n+1])%=mo;
		(ans+=inv[n]%mo*(mo+1-w*inv[n]%mo)%mo)%=mo;
	}
	ans=ans*2%mo;
	printf("%d\n",(mo+1-ans)%mo);
}
int main(){
	inv[1]=1;
	for(int i=2;i<maxn;i++)inv[i]=inv[mo%i]*(mo-mo/i)%mo;
	for(int i=1000000;i;i--)s[i]=(s[i+1]+inv[i])%mo;
	while(~scanf("%d",&n))work();
	return 0;
}
