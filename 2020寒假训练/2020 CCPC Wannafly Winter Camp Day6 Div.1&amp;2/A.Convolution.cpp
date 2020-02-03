#include<bits/stdc++.h>
using namespace std;
#define mo 998244353
#define LL long long
LL Pow(LL a,int b){
	LL ans=1;
	while(b){
		if(b&1)(ans*=a)%=mo;
		(a*=a)%=mo,b>>=1;
	}
	return ans;
}
int main(){
	int n,x,sum=0,ans=0;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x),x=Pow(2,x);
		(sum+=x)%=mo,(ans+=Pow(sum,x))%=mo;
	}
	printf("%d",ans);
	return 0;
}
