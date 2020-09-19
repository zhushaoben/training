#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mo=998244353;
int l[10],r[10],f[N],s[10];
int main(){
	int n,k;scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++)scanf("%d%d",l+i,r+i),r[i]++;
	f[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<k;j++){
			if(i-r[j]>=0)(s[j]-=f[i-r[j]])%=mo;
			if(i-l[j]>=0)(s[j]+=f[i-l[j]])%=mo;
			(f[i]+=s[j])%=mo;
		}
	}
	printf("%d",(f[n]+mo)%mo);
	return 0;
}
