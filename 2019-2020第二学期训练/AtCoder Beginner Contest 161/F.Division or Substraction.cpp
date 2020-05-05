#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL n,n1;scanf("%lld",&n);
	if(n==2)return puts("1"),0;
	int q=sqrt(n),ans=0;
	for(int i=2;i<=q;i++){
		if(n%i==0){
			LL w=n/i;n1=n;
			while(n1%i==0)n1/=i;
			if(n1%i==1)ans++;
			n1=n;
			if(w==i)continue;
			while(n1%w==0)n1/=w;
			if(n1%w==1)ans++;
		}
		else if((n-1)%i==0){
			ans+=2;
			if(1ll*i*i==n-1)ans--;
		}
	}
	printf("%d",ans+2);
	return 0;
}
