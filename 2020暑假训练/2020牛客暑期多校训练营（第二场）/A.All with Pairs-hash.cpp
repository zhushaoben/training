#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mo=998244353;
typedef unsigned long long uLL;
char s[N*2];
int nex[N*2];
unordered_map<uLL,int> mp;
uLL base[N],seed=5467;
int main(){
	int n,l=0,r,ans=0,si;scanf("%d",&n);
	base[0]=1;for(int i=1;i<N;i++)base[i]=base[i-1]*seed;
	for(int i=0;i<n;i++){
		scanf("%s",s+(++l));
		nex[l-1]=l-2;
		for(r=l;s[r];r++){
			int p=nex[r-1];
			while(p>=l-1&&s[p+1]!=s[r])p=nex[p];
			nex[r]=p+1;
		}
		r--;uLL hash=0;
		for(int j=r;s[j];j--){
			hash=hash+s[j]*base[r-j];
			mp[hash]++;
		}
		l=r+1;
	}
	l=0;
	for(int i=0;i<n;i++){
		uLL hash=0;
		for(r=(++l),si=1;s[r];si++,r++){
			hash=hash*seed+s[r];
			ans=(ans+(1ll*mp[hash]*si%mo*si%mo))%mo;
			int p=nex[r],si1=p-l+1;
			if(si1)ans=(ans-1ll*mp[hash]*si1%mo*si1%mo)%mo;
		}
		l=r;
	}
	printf("%d",(ans+mo)%mo);
	return 0;
}
