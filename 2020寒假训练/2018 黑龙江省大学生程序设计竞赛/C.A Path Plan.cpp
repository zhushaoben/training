#include<bits/stdc++.h>
using namespace std;
#define mo 1000000007
#define maxn 200000
int fac[maxn*2],inv[maxn*2];
int Pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mo;
		a=1ll*a*a%mo;b>>=1;
	}
	return ans;
}
int C(int m,int n){
	return 1ll*fac[m]*inv[n]%mo*inv[m-n]%mo;
}
void work(){
	int x1,x2,y1,y2;
	scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
	printf("%d\n",(mo+1ll*C(x1+y1,x1)*C(x2+y2,x2)%mo-1ll*C(x1+y2,x1)*C(x2+y1,x2)%mo)%mo);
}
int main(){
	int t;scanf("%d",&t);
	fac[0]=1;
	for(int i=1;i<=maxn;i++)fac[i]=1ll*fac[i-1]*i%mo;
	inv[maxn]=Pow(fac[maxn],mo-2);
	for(int i=maxn-1;~i;i--)inv[i]=1ll*inv[i+1]*(i+1)%mo;
	while(t--)work();
	return 0;
} 
