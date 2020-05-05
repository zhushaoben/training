#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7;
typedef long long LL;
LL Power(LL a,int b){
	LL ans=1;
	while(b){
		if(b&1)(ans*=a)%=mo;
		(a*=a)%=mo,b>>=1;
	}
	return ans;
}
void work(){
	int n,m;scanf("%d%d",&n,&m);
	printf("%d\n",Power(2,n-1)*m%mo);
}
int main(){
	int T=1;
	scanf("%d",&T);
	while(T--)work();
	return 0;
} 
