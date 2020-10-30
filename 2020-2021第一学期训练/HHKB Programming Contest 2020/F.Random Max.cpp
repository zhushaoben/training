#include<bits/stdc++.h>
using namespace std;
const int N=1005,mo=1e9+7;
struct Node{
	int l,r;
	bool operator <(const Node &b)const{return r>b.r;}
}a[N];
void Inverse(int p,int a[],int n){//线性求<=n的数%p意义下的逆元 
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=1ll*(p-p/i)*a[p%i]%p;
	}
}
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mo;
		a=1ll*a*a%mo,b>>=1;
	}
	return ans;
}
int w[N],inv[N],fac,si=1;
void calc(int l){//w*=(x-l)
	si++;
	for(int i=si;i;i--)w[i]=((w[i-1]-1ll*w[i]*l)%mo+mo)%mo;
	w[0]=((-1ll*w[0]*l%mo)+mo)%mo;
}
int calc1(int l,int r){
	int ans=0,l1=1,r1=1;
	for(int i=0;i<=si;i++)
		(ans+=1ll*w[i]*fac%mo*inv[i+1]%mo*(r1-l1+mo)%mo)%=mo,l1=1ll*l1*l%mo,r1=1ll*r1*r%mo;
	return ans;
}
int main(){
	int n,mal=0,d=1,ans=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",&a[i].l,&a[i].r),mal=max(mal,a[i].l),d=1ll*d*(a[i].r-a[i].l)%mo;
	fac=1;for(int i=1;i<=n+1;i++)fac=1ll*fac*i%mo;
	Inverse(mo,inv,n+1);
	sort(a,a+n);w[1]=1;
	for(int i=0;i<n;i++){
		if(a[i].r<=mal)break;
		calc(a[i].l);d=1ll*d*qpow(a[i].r-a[i].l,mo-2)%mo;
		(ans+=1ll*calc1(max(a[i+1].r,mal),a[i].r)*d%mo)%=mo;
	}
	printf("%d",ans);
	return 0;
}
