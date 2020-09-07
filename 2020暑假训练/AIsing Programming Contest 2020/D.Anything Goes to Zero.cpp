#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int f[N],ans[N];
char s[N];
int main(){
	int n,sum=0,s1,s2,sum1=0,sum2=0,d1=1,d2=1;scanf("%d%s",&n,s);
	for(int i=0;s[i];i++)sum+=(s[i]^=0x30);s1=sum-1,s2=sum+1;
	f[0]=1;for(int i=1;i<=s2;i++)f[i]=1+f[i%__builtin_popcount(i)];
	if(s1)for(int i=n-1;~i;i--)(sum1+=s[i]*d1)%=s1,(sum2+=s[i]*d2)%=s2,d1=d1*2%s1,d2=d2*2%s2;
	else for(int i=n-1;~i;i--)(sum2+=s[i]*d2)%=s2,d2=d2*2%s2;
	d1=d2=1;
	for(int i=n-1;~i;i--){
		if(s[i])ans[i]=s1?f[(sum1-d1+s1)%s1]:0;
		else ans[i]=f[(sum2+d2)%s2];
		d2=d2*2%s2;if(s1)d1=d1*2%s1;
	}
	for(int i=0;i<n;i++)printf("%d\n",ans[i]);
	return 0;
}
