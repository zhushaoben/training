#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7,inv=5e8+4;
int pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mo;
		a=1ll*a*a%mo,b>>=1;
	}
	return ans;
}
int a[505];
void work(){
	int n,ans=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i),ans+=a[i]/2;
	for(int i=1;i<n;i++){
		(ans-=(1ll*a[i]/2*a[i-1]/2%mo)*(pow(a[i-1],mo-2)+pow(a[i],mo-2))%mo)%=mo;
	}
	printf("%d\n",(ans+mo)%mo);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
