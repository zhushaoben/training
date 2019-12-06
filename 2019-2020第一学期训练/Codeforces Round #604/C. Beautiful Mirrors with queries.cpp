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
int w[maxn],inv[maxn],b[maxn];
int calc(int l,int r){
	return (1ll*(w[l]-w[r+1])*inv[r+1]%mo+mo)%mo;
}
int main(){
	int n,q,a=Pow(100,mo-2),x;scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",w+i);w[i]=1ll*w[i]*a%mo;
		w[i]=Pow(w[i],mo-2);
	}
	inv[n+1]=w[n+1]=1;
	for(int i=n;i;i--){
		w[i]=1ll*w[i]*w[i+1]%mo;
		inv[i]=Pow(w[i],mo-2)%mo;
	}w[n+1]=0;
	for(int i=n;i;i--)(w[i]+=w[i+1])%=mo;
	set<int>S;S.insert(1),S.insert(n+1);
	LL ans=calc(1,n);
	for(int i=0;i<q;i++){
		scanf("%d",&x);
		b[x]^=1;
		if(b[x]){
			S.insert(x);
			auto pr=S.find(x),ne=pr;
			pr--,ne++;
			(ans-=calc(*pr,*ne-1))%=mo;
			ans=(mo+ans+calc(*pr,x-1)+calc(x,*ne-1))%mo;
		}
		else{
			auto pr=S.find(x),ne=pr;
			pr--,ne++;
			S.erase(x);
			(ans+=calc(*pr,*ne-1))%=mo;
			ans=(2ll*mo+ans-calc(*pr,x-1)-calc(x,*ne-1))%mo;
		}
		printf("%d\n",ans);
	}
	return 0;
}
