#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mo 998244353
#define maxn 200005
LL Pow(LL a,int b){
	LL ans=1;
	while(b){
		if(b&1)(ans*=a)%=mo;
		(a*=a)%=mo,b>>=1;
	}
	return ans;
}
int w[maxn];
int main(){
	int n,a=Pow(100,mo-2),x;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",w+i);w[i]=Pow(1ll*w[i]*a%mo,mo-2);
	}
	for(int i=n-1;i;i--)w[i]=1ll*w[i]*w[i+1]%mo;
	for(int i=n-1;i;i--)(w[i]+=w[i+1])%=mo;
	printf("%d",w[1]);
	return 0;
}
