#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7,N=2e5+5;
typedef long long LL;
void Inverse(int p,int a[],int n){//������<=n����%p�����µ���Ԫ 
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=1ll*(p-p/i)*a[p%i]%p;
	}
}
LL Pow(LL a,int b){
	LL ans=1;
	while(b){
		if(b&1)(ans*=a)%=mo;
		(a*=a)%=mo,b>>=1;
	}
	return ans;
}
int inv[N];
LL C(int n,int a){
	LL ans=1;
	for(int i=1;i<=a;i++)ans=ans*(n-i+1)%mo*inv[i]%mo;
	return ans;
}
int main(){
	int n,a,b;scanf("%d%d%d",&n,&a,&b);
	Inverse(mo,inv,b);
	printf("%d",((Pow(2,n)-C(n,a)-C(n,b)-1)%mo+mo)%mo);
	return 0;
}
