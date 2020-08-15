#include<bits/stdc++.h>
using namespace std;
const int N=3005,mo=998244353;
int f[N];
int main(){
	int n,x,s;scanf("%d%d",&n,&s);
	f[0]=1;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		for(int i=s;i>=x;i--)(f[i]+=(f[i-x]+f[i])%mo)%=mo;
		for(int i=x-1;~i;i--)f[i]=f[i]*2%mo;
	}
	printf("%d",f[s]);
	return 0;
}
