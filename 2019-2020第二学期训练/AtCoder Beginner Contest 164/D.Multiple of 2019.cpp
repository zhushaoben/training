#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char s[N];
int num[3000];
int main(){
	num[0]=1;scanf("%s",s);
	long long ans=0;int l=strlen(s),now=0,d=1;
	for(int i=l-1;~i;i--){
		(now+=d*(s[i]-'0'))%=2019,(d*=10)%=2019;
		ans+=num[now]++;
	}
	printf("%lld",ans);
	return 0;
}
