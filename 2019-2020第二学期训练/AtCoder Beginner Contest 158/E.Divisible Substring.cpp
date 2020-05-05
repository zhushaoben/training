#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long LL;
char s[N];
int num[N];
int main(){
	int n,k,sum=0,d=1;LL ans=0;scanf("%d%d%s",&n,&k,s);
	if(k==2||k==5){
		for(int i=0;s[i];i++)if((s[i]-'0')%k==0)ans+=i+1;
		return printf("%lld\n",ans),0;
	}
	num[0]++;
	for(int i=n-1;~i;i--){
		(sum+=(s[i]-'0')*d)%=k,d=d*10%k;
		ans+=num[sum],num[sum]++;
	}
	printf("%lld\n",ans);
	return 0;
}
