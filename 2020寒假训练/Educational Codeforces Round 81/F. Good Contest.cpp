#include<bits/stdc++.h>
using namespace std;
#define maxn 55
#define mo 998244353
#define LL long long
int Pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mo;
		a=1ll*a*a%mo,b>>1;
	}
	return ans;
} 
int f[maxn][maxn*2],b[maxn*2],l[maxn],r[maxn];
LL calc(int x,int i){
	return 1ll**Pow(r[x]-l[x]+1,mo-2)%mo;
}
int main(){
	int n,si;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",l+i,r+i),b[i<<1]=l[i]-1,b[i<<1|1]=r[i];
	f[0][0]=1;sort(b,b+n);si=unique(b,b+n)-b;
	for(int i=1;i<=n;i++){
		for(int j=0;j<si;j++){
			for(int k=0;k<j;k++)(f[i][j]+=f[i-1][j]%=mo);
			f[i][j]=calc(i-1,j)*f[i][j]%mo;
		}
	}
	printf("%d",f[n][si]);
	return 0;
}
